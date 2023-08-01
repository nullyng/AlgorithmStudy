#include <iostream>

using namespace std;

const int MAX = 16;

int N;
int house[MAX][MAX];
int dp[3][MAX][MAX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      cin >> house[i][j];

  dp[0][0][1] = 1;

  for(int i = 2; i < N; i++) {
    if(house[0][i]) break;
    dp[0][0][i] = 1;
  }
    
  
  for(int i = 1; i < N; i++) {
    for(int j = 1; j < N; j++) {
      // 가로, 세로
      if(!house[i][j]) {
        dp[0][i][j] = dp[0][i][j - 1] + dp[2][i][j - 1];
        dp[1][i][j] = dp[1][i - 1][j] + dp[2][i - 1][j];
      }
      // 대각선
      if(!house[i][j] && !house[i - 1][j] && !house[i][j - 1]) {
        dp[2][i][j] = dp[0][i - 1][j - 1] + dp[1][i - 1][j - 1] + dp[2][i - 1][j - 1];
      }
    }
  }

  cout << dp[0][N - 1][N - 1] + dp[1][N - 1][N - 1] + dp[2][N - 1][N - 1];

  return 0;
}