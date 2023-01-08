#include <string>
#include <vector>

using namespace std;

int parent[200];

int Find(int u, int origin) {
    if (parent[u] == u) {
        parent[origin] = u;
        return u;
    }

    return Find(parent[u], origin);
}

void Union(int u, int v) {
    parent[u] = v;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int u, v;

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;

            if (computers[i][j]) {
                u = Find(i, i);
                v = Find(j, j);

                if (u != v) {
                    Union(u, v);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
        if (parent[i] == i)
            answer++;

    return answer;
}