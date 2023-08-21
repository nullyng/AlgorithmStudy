#include <iostream>
#include <cstring>
using namespace std;

int T, N, M;
int coin[21];
int dp[10001];

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> T;
  while(T--) {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> coin[i];
    cin >> M;

    memset(dp, 0, sizeof(dp));

    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
      for (int j = coin[i]; j <= M; j++) {
        dp[j] += dp[j - coin[i]];
      }
    }

    cout << dp[M] << "\n";
  }

  return 0;
}