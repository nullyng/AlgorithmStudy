#include <iostream>
#define MOD 1000000007
using namespace std;

int N;
long long dp[1000001];
int sum;

int main() {
  dp[0] = 0;
  dp[1] = 2;
  dp[2] = 7;
  sum = 1;

  cin >> N;
  for (int i = 3; i <= N; i++) {
    sum = (dp[i-3] + sum) % MOD; // n-3의 경우의 수 + n-4까지의 합
    dp[i] = (2*dp[i-1] + 3*dp[i-2] + 2*sum) % MOD;
  }

  cout << dp[N] << "\n";
  return 0;
}