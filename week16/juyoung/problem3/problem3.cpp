#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str1, str2;
int l1, l2;
int dp[1001][1001];
string lcs;

void dfs(int y, int x, int n) {
  if (dp[y][x] == 0) return;

  if(dp[y-1][x] == n) {
    dfs(y - 1, x, n);
  } else if(dp[y][x-1] == n) {
    dfs(y, x - 1, n);
  } else {
    lcs += str1[y-1];
    dfs(y - 1, x - 1, dp[y - 1][x - 1]);
  }
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> str1 >> str2;
  l1 = str1.length();
  l2 = str2.length();

  for (int i = 1; i <= l1; i++) {
    for (int j = 1; j <= l2; j++) {
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      if(str1[i-1] == str2[j-1]) dp[i][j] = max(dp[i-1][j-1]+1, dp[i][j]);
    }
  }

  dfs(l1, l2, dp[l1][l2]);
  reverse(lcs.begin(), lcs.end());

  cout << dp[l1][l2] << "\n";
  cout << lcs << "\n";

  return 0;
}