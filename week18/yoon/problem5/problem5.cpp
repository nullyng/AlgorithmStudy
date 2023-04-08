#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

bool res = true;
int N, M, a, b;
vector<int> parent(2001);
vector<vector<int>> graph(2001);
vector<int> visited(2001, -1);

void bfs(int root) {
    queue<pair<int, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto [here, depth] = q.front();
        q.pop();

        if (visited[here] == -1)
            visited[here] = depth;

        for (auto next : graph[here]) {
            if (visited[next] == -1) {
                q.push({next, depth + 1});
            } else {
                if (!(abs(visited[next] - visited[here]) & 1)) {
                    res = false;
                }
            }
        }
    }
}

int find(int a) {
    if (parent[a] == a)
        return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    parent[pa] = pb;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        parent[i] = i;

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        merge(a, b);
    }

    unordered_set<int> s;
    for (int i = 1; i <= N; i++) {
        s.insert(find(i));
    }

    for (auto i : s) {
        bfs(i);
    }

    cout << (res ? 1 : 0);

    return 0;
}
