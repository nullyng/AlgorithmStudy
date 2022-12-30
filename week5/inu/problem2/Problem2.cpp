#include <iostream>

using namespace std;

int LCS[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s1, s2;

    cin >> s1 >> s2;

    int len1 = (int)s1.size();
    int len2 = (int)s2.size();

    for (int i = 1; i <= len2; i++) {
        for (int j = 1; j <= len1; j++) {
            if (s1[j - 1] == s2[i - 1]) {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            }
            else {
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
    }

    cout << LCS[len2][len1];

    return 0;
}