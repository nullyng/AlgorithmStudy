#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

ll pick(vector<vector<ll>> &sum, int N, int M, int i, int j) {
    ll a, b, c, d;
    a = sum[i][j];
    b = sum[i][M - 1] - a;
    c = sum[N - 1][j] - a;
    d = sum[N - 1][M - 1] - a - b - c;

    return max((a + b) * c * d,
               max((a + c) * b * d, max((b + d) * a * c, (c + d) * a * b)));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    string s;
    vector<vector<int>> map(N, vector<int>(M));
    vector<vector<ll>> sum(N, vector<ll>(M, 0));
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            map[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i >= 1 && j >= 1)
                sum[i][j] -= sum[i - 1][j - 1];
            if (i >= 1)
                sum[i][j] += sum[i - 1][j];
            if (j >= 1)
                sum[i][j] += sum[i][j - 1];
            sum[i][j] += map[i][j];
        }
    }

    ll res = 0;
    if (N != 1 && M != 1) {
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < M - 1; j++) {
                res = max(res, pick(sum, N, M, i, j));
            }
        }
    }

    for (int i = 0; i < M - 2; i++) {
        for (int j = i + 1; j < M - 1; j++) {
            res = max(res, sum[N - 1][i] * (sum[N - 1][j] - sum[N - 1][i]) *
                               (sum[N - 1][M - 1] - sum[N - 1][j]));
        }
    }

    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            res = max(res, sum[i][M - 1] * (sum[j][M - 1] - sum[i][M - 1]) *
                               (sum[N - 1][M - 1] - sum[j][M - 1]));
        }
    }

    cout << res;

    return 0;
}
