#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

typedef struct edge {
	int v, k;
}edge;

int T, N, M, W;
vector<edge> graph[501];

vector<ll> bellmanFord() {
	vector<ll> upper(N + 1, 0);
	bool success;

	for (int i = 0; i < N; i++) {
		success = false;

		for (int u = 1; u <= N; u++) {
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

	if (success) 
		upper.clear();

	return upper;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	for (int t = 0; t < T; t++) {
		int u, v, k;

		cin >> N >> M >> W;

		for (int i = 1; i <= N; i++)
			graph[i].clear();

		for (int i = 0; i < M; i++) {
			cin >> u >> v >> k;
			graph[u].push_back({ v, k });
			graph[v].push_back({ u, k });
		}

		for (int i = 0; i < W; i++) {
			cin >> u >> v >> k;
			graph[u].push_back({ v, -k });
		}

		vector<ll> upper = bellmanFord();

		if (upper.empty()) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}