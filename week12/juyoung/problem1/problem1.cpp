#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N, d, w;
  vector<pair<int, int>> v;
  int days = 0;
  int answer = 0;

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> d >> w;
    days = max(days, d);
    v.push_back({-w, d});
  }

  sort(v.begin(), v.end());

  while (days > 0) {
    for (int i = 0; i < v.size(); i++) {
      if(v[i].second >= days) {
        answer += -v[i].first;
        v.erase(v.begin() + i);
        break;
      }
    }
    days--;
  }

  cout << answer << "\n";
  return 0;
}