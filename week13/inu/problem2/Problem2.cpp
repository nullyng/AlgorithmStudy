#include <string>
#include <vector>

using namespace std;

int dp[500][500];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int last = (int)triangle.size() - 1;

    dp[0][0] = triangle[0][0];

    for (int i = 1; i <= last; i++) {
        int pre = (int)triangle[i - 1].size() - 1;
        int len = (int)triangle[i].size() - 1;

        dp[i][0] = dp[i - 1][0] + triangle[i][0];
        dp[i][len] = dp[i - 1][pre] + triangle[i][len];

        for (int j = 1; j < len; j++) {
            dp[i][j] = triangle[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
        }
    }

    for (int i = 0; i < (int)triangle[last].size(); i++)
        answer = max(answer, dp[last][i]);

    return answer;
}