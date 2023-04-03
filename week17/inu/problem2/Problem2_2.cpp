#include <iostream>

using namespace std;

int dp[4000][4000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string s1, s2;
  int max_len = 0;
  
  cin >> s1 >> s2;

  for(int i = 0; i < (int)s1.length(); i++) {
    for(int j = 0; j < (int)s2.length(); j++) {
      if(s1[i] == s2[j]) {
        dp[i][j] = 1;

        if(i >= 1 && j >= 1)
          dp[i][j] += dp[i - 1][j - 1];
        
        max_len = max(max_len, dp[i][j]);
      }
    }
  }

  cout << max_len;

  return 0;
}