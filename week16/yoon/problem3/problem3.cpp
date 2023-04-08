#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(string s1, string s2, int i, int j, vector<vector<int>> &dp) {
    if (dp[i][j] == 0)
        return;

    if (s1[i - 1] == s2[j - 1]) {
        print(s1, s2, i - 1, j - 1, dp);
        cout << s1[i - 1];
    } else
        dp[i - 1][j] > dp[i][j - 1] ? print(s1, s2, i - 1, j, dp)
                                    : print(s1, s2, i, j - 1, dp);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;

    vector<vector<int>> dp(1002, vector<int>(1002, 0));

    for (int i = 0; i < s1.size(); i++) {
        for (int j = 0; j < s2.size(); j++) {
            if (s1[i] == s2[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }

    int resSize = dp[s1.size()][s2.size()];
    cout << resSize << endl;

    print(s1, s2, s1.size(), s2.size(), dp);

    return 0;
}
