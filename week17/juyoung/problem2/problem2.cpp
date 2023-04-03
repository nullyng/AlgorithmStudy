#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s1, s2;
int dp[4001][4001];
int answer = 0;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> s1 >> s2;

  for (int i = 1; i <= s1.length(); i++) {
    for (int j = 1; j <= s2.length(); j++) {
      if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i - 1][j - 1] + 1;
      answer = max(dp[i][j], answer);
    }
  }

  cout << answer << "\n";
  return 0;
}