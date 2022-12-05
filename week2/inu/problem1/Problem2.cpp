#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> graph;
vector<bool> visited;

int dfs(int u, int depth) {
	visited[u] = true;

	if (depth >= 5) {
		return 1;
	}

	for (int i = 0; i < (int)graph[u].size(); i++) {
		int v = graph[u][i];

		if (!visited[v]) {
			if (dfs(v, depth + 1)) {
				return 1;
			}
		}
	}

	visited[u] = false;

	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int u, v;
	int result = 0;

	cin >> N >> M;

	graph.assign(N, vector<int>());

	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 0; i < N; i++) {
		visited.assign(N, false);
		result = dfs(i, 1);

		if (result) break;
	}

	cout << result;

	return 0;
}