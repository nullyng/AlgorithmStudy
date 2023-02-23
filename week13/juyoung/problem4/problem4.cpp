#include <iostream>
#include <algorithm>
#define INF 999999
using namespace std;

int n, k;
int coin[101];
int dp[10001];

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n >> k;

  for (int i = 1; i <= k; i++) dp[i] = INF;

  for (int i = 0; i < n; i++) {
    cin >> coin[i];
    if(coin[i] <= 10000) dp[coin[i]] = 1;
  }

  sort(coin, coin + n);

  for (int i = 0; i < n; i++) {
    for (int j = coin[i]; j <= k; j++) {
      dp[j] = min(dp[j], dp[j - coin[i]] + 1);
    }
  }

  if(dp[k] == INF) cout << "-1\n";
  else cout << dp[k] << "\n";

  return 0;
}