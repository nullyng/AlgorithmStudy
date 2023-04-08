#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> map(N + 1, vector<int>(M + 1));

    string s;
    for (int i = 1; i <= N; i++) {
        cin >> s;
        for (int j = 0; j < M; j++) {
            if (s[j] == '0') {
                map[i][j + 1] = 0;
            } else {
                map[i][j + 1] = 1;
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (map[i][j] != 0)
                map[i][j] =
                    min(map[i - 1][j - 1], min(map[i - 1][j], map[i][j - 1])) +
                    1;
            res = max(res, map[i][j]);
        }
    }

    cout << res * res;

    return 0;
}
