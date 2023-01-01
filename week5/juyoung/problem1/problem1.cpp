#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N;
  vector<pair<int, int>> line;
  vector<int> dp;
  int answer = 0;

  cin >> N;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    line.push_back({a, b});
    dp.push_back(1);
  }

  sort(line.begin(), line.end());

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) {
      if(line[i].second > line[j].second) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
      answer = max(dp[i], answer);
    }
  }

  cout << N - answer << "\n";

  return 0;
}