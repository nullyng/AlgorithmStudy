#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> graph_h;
vector<vector<int>> graph_l;

void DFS(int cur, vector<bool>& visited, vector<vector<int>> graph) {
	for (int i = 0; i < (int)graph[cur].size(); i++) {
		int u = graph[cur][i];

		if (!visited[u]) {
			visited[u] = true;
			DFS(u, visited, graph);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	graph_h.assign(N + 1, vector<int>());
	graph_l.assign(N + 1, vector<int>());

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph_h[u].push_back(v);
		graph_l[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		vector<bool> visited1(N + 1, false);
		visited1[i] = true;
		DFS(i, visited1, graph_h);

		vector<bool> visited2(N + 1, false);
		visited2[i] = true;
		DFS(i, visited2, graph_l);

		int cnt = 0;

		for (int n = 1; n <= N; n++)
			if (!visited1[n] && !visited2[n])
				cnt++;

		cout << cnt << '\n';
	}

	return 0;
}