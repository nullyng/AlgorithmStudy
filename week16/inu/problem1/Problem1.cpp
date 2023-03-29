#include <iostream>
#include <vector>

#define MAX 10001

using namespace std;

int dp[MAX];
vector<int> coin;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, k;

  cin >> n >> k;

  for(int i = 0; i < n; i++) {
    int v;
    cin >> v;
    coin.push_back(v);
  }

  dp[0] = 1;

  for(int c : coin) {
    for(int i = c; i <= k; i++)
      dp[i] += dp[i - c];
  }

  cout << dp[k];

  return 0;
}