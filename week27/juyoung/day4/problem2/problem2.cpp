#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;

int C, N;
int dp[1101];
int answer = 1e9;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> C >> N;

  for(int i = 1; i <= C + 100; i++) dp[i] = INF;
  for (int i = 0; i < N; i++) {
    int cost, customer;
    cin >> cost >> customer;
    dp[customer] = min(dp[customer], cost);
  }

  for (int i = 2; i <= C + 100; i++) {
    for (int j = i - 1; j >= 1; j--) {
      dp[i] = min(dp[i], dp[j] + dp[i-j]);
    }
  }

  for (int i = C; i <= C + 100; i++) answer = min(answer, dp[i]);

  cout << answer << "\n";
  return 0;
}