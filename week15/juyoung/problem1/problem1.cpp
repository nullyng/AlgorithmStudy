#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N, S, T;
  map<int, int> m;

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> S >> T;
    m[S]++; m[T]--;
  }

  int sum = 0;
  int answer = 0;
  for (auto iter = m.begin(); iter != m.end(); iter++) {
    sum += iter->second;
    answer = max(answer, sum);
  }

  cout << answer << "\n";
  return 0;
}