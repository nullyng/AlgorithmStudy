#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int N, M;

int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};
// R D L U

int map[1001][1001];
int parent[1001 * 1001];

int find(int a) {
    if (a == parent[a])
        return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa == pb)
        return;
    parent[pa] = parent[pb];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    string t;
    for (int i = 0; i < N; i++) {
        cin >> t;
        for (int j = 0; j < t.size(); j++) {
            switch (t[j]) {
            case 'R':
                map[i][j] = 0;
                break;
            case 'D':
                map[i][j] = 1;
                break;
            case 'L':
                map[i][j] = 2;
                break;
            case 'U':
                map[i][j] = 3;
                break;
            default:
                break;
            }
        }
    }

    for (int i = 0; i < 1001 * 1001; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int xi = i + di[map[i][j]];
            int xj = j + dj[map[i][j]];
            int a = i * M + j;
            int b = xi * M + xj;
            merge(a, b);
        }
    }

    unordered_set<int> res;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            res.insert(find(i * M + j));
        }
    }

    cout << res.size();

    return 0;
}
