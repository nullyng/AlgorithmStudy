#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int answer;
vector<int> v[10001];
priority_queue<int> pq;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int p, d;
    cin >> p >> d;
    v[d].push_back(p);
  }

  for (int i = 10000; i > 0; i--) {
    for(auto p: v[i]) pq.push(p);
    if(!pq.empty()) {
      answer += pq.top();
      pq.pop();
    }
  }

  cout << answer << "\n";
  return 0;
}