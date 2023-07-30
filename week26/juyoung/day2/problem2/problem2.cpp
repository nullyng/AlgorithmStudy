#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;

int n, k;
int value[101];
int dp[10001];

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n >> k;
  for (int i = 1; i <= k; i++) dp[i] = INF;
  for (int i = 0; i < n; i++) {
    cin >> value[i];
    if(value[i] <= 10000) dp[value[i]] = 1;
  }

  sort(value, value + n);

  for (int i = 0; i < n; i++) {
    for (int j = value[i]; j <= k; j++) {
      dp[j] = min(dp[j], dp[j - value[i]] + 1);
    }
  }

  if(dp[k] == INF) cout << "-1\n";
  else cout << dp[k] << "\n";

  return 0;
}