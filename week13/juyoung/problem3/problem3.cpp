#include <string>
#include <vector>
#define MOD 1000000007

using namespace std;

int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    for(int i=0; i<puddles.size(); i++)
        dp[puddles[i][1]][puddles[i][0]] = -1;
    for(int i=2; i<=n; i++) {
        if(dp[i][1] == -1) break; 
        dp[i][1] = 1;
    }
    for(int i=2; i<=m; i++) {
        if(dp[1][i] == -1) break;
        dp[1][i] = 1;
    }
    
    for(int i=2; i<=n; i++) {
        for(int j=2; j<=m; j++) {
            if(dp[i][j] == -1) continue;
            if(dp[i-1][j] == -1) dp[i][j] = dp[i][j-1] % MOD;
            else if(dp[i][j-1] == -1) dp[i][j] = dp[i-1][j] % MOD;
            else if(dp[i-1][i] == -1 && dp[i][j-1] == -1) dp[i][j] = 0;
            else dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }
    
    return dp[n][m];
}