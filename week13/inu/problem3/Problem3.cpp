#include <string>
#include <vector>
#define MOD 1000000007

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> map;

    map.assign(n, vector<int>(m, 0));

    for (vector<int> puddle : puddles) {
        map[puddle[1] - 1][puddle[0] - 1] = -1;
    }

    // ∏« ¿≠¡Ÿ
    for (int j = 1; j < m; j++) {
        if (map[0][j] == -1) break;
        map[0][j] = 1;
    }
    // ∏« øﬁ¬ 
    for (int i = 1; i < n; i++) {
        if (map[i][0] == -1) break;
        map[i][0] = 1;
    }
    // ≥™∏”¡ˆ
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (map[i][j] == -1) continue;

            int up = map[i - 1][j];
            int left = map[i][j - 1];

            if (up == -1) up = 0;
            if (left == -1) left = 0;

            map[i][j] = (up % MOD) + (left % MOD);
            map[i][j] %= MOD;
        }
    }

    answer = map[n - 1][m - 1];

    return answer;
}