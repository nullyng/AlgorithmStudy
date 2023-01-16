#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define INF 999999

using namespace std;

typedef struct edge {
	int v, k;
}edge;

int house[100];
vector<int> dist;
vector<edge> graph[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	queue<edge> q;
	int N, V, E;
	int A, B;
	int u, v, k;
	int sum = 0;

	cin >> N >> V >> E;
	cin >> A >> B;

	for (int i = 0; i < N; i++)
		cin >> house[i];

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> k;
		graph[u].push_back({ v, k });
		graph[v].push_back({ u, k });
	}

	for (int i = 0; i < N; i++) {
		int h = house[i];
		queue<edge> q;

		dist.assign(V + 1, INF);
		dist[h] = 0;

		q.push({ h, 0 });

		while (!q.empty()) {
			edge e = q.front();
			q.pop();

			u = e.v;
			k = e.k;

			if (dist[u] < k)
				continue;

			for (int i = 0; i < (int)graph[u].size(); i++) {
				v = graph[u][i].v;
				k = graph[u][i].k;

				if (dist[u] + k < dist[v]) {
					dist[v] = dist[u] + k;
					q.push({ v, k });
				}
			}
		}

		sum += dist[A] == INF ? -1 : dist[A];
		sum += dist[B] == INF ? -1 : dist[B];
	}

	cout << sum;

	return 0;
}