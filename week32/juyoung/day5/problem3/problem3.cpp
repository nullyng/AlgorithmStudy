#include <iostream>
#define MOD 1000000000
using namespace std;

int N, K;
long long dp[5001][5001]; // k개를 골랐을 때 그 합이 n인 경우의 수

int main() {
  cin >> N >> K;

  for (int i = 1; i <= K; i++) dp[1][i] = i;
  for (int i = 1; i <= N; i++) dp[i][1] = 1;

  for (int i = 2; i <= N; i++) {
    for (int j = 2; j <= K; j++) {
      dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
    }
  }

  cout << dp[N][K] << "\n";
  return 0;
}