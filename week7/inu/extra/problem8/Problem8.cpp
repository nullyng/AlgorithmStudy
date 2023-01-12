#include <iostream>
#include <vector>
#include <queue>
#define INF INT64_MAX

using namespace std;

typedef struct edge {
	int v, k;

	bool operator<(const edge& e) const {
		return k < e.k;
	}
}edge;

int N, M, K;
long long dist[10001][21];
vector<edge> graph[10001];

void dijkstra() {
	for (int i = 2; i <= N; i++)
		for (int j = 0; j <= K; j++)
			dist[i][j] = INF;

	int u, v, r;
	long long k;
	priority_queue<pair<long long, edge>> pq;
	pq.push({ 0, {1, 0} });

	while (!pq.empty()) {
		k = -pq.top().first;
		u = pq.top().second.v;
		r = pq.top().second.k;
		pq.pop();

		if (dist[u][r] < k)
			continue;

		for (edge e : graph[u]) {
			v = e.v;
			k = e.k;

			if (dist[u][r] + k < dist[v][r]) {
				dist[v][r] = dist[u][r] + k;
				pq.push({ -dist[v][r], {v, r} });
			}

			if (r < K) {
				if (dist[u][r] < dist[v][r + 1]) {
					dist[v][r + 1] = dist[u][r];
					pq.push({ -dist[v][r + 1], {v, r + 1} });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		int u, v, k;
		cin >> u >> v >> k;
		graph[u].push_back({ v, k });
		graph[v].push_back({ u, k });
	}

	dijkstra();

	long long ans = INF;

	for (int i = 0; i <= K; i++) {
		ans = min(dist[N][i], ans);
	}

	cout << ans;

	return 0;
}