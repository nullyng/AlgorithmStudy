#include <iostream>
#include <vector>

using namespace std;

typedef struct edge {
	int v, k;
}edge;

int N, M;
vector<edge> graph[501];
vector<int> upper;

vector<long long> bellmanFord(int src) {
	vector<long long> upper(N + 1, INT64_MAX);
	upper[src] = 0;
	bool success;

	for (int i = 0; i < N; i++) {
		success = false;

		for (int u = 1; u <= N; u++) {
			if (upper[u] == INT64_MAX)
				continue;

			for (int cur = 0; cur < (int)graph[u].size(); cur++) {
				int v = graph[u][cur].v;
				int k = graph[u][cur].k;

				if (upper[v] > upper[u] + k) {
					upper[v] = upper[u] + k;
					success = true;
				}
			}
		}

		if (!success) break;
	}

	if (success) upper.clear();
	return upper;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	int u, v, k;

	for (int i = 0; i < M; i++) {
		cin >> u >> v >> k;
		graph[u].push_back({ v, k });
	}

	vector<long long> upper = bellmanFord(1);

	if (upper.empty()) {
		cout << -1;
	}
	else {
		for (int i = 2; i <= N; i++) {
			if (upper[i] != INT64_MAX)
				cout << upper[i] << '\n';
			else
				cout << -1 << '\n';
		}
			
	}

	return 0;
}