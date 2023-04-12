#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define MAX 2001
#define INF 200000000

using namespace std;

typedef struct info {
	int v, t, h;
}info;

vector<info> graph[MAX];
int dist[MAX][201];
// dist[i][j]: i섬에 j 높이의 뗏목으로 오는데 걸리는 최소 시간

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int K, N, M;
	int A, B;

	cin >> K >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b, t, h;
		cin >> a >> b >> t >> h;
		graph[a].push_back({ b, t, h });
		graph[b].push_back({ a, t, h });
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= K; j++)
			dist[i][j] = INF;

	cin >> A >> B;

	queue<info> q;
	q.push({ A, 0, K });
	dist[A][K] = 0;

	while (!q.empty()) {
		int u = q.front().v;
		int t = q.front().t;
		int h = q.front().h;
		q.pop();

		if (u == B) continue;
		if (dist[u][h] < t) continue;

		for (int i = 0; i < (int)graph[u].size(); i++) {
			int v = graph[u][i].v;
			int w = graph[u][i].t;
			int h_ = graph[u][i].h;
			int new_h = h - h_;

			if (new_h > 0 && dist[v][new_h] > dist[u][h] + w) {
				dist[v][new_h] = dist[u][h] + w;
				q.push({ v, dist[v][new_h], new_h });
			}
		}
	}

	int min_t = INF;
	for (int i = 1; i <= K; i++)
		min_t = min(dist[B][i], min_t);

	if (min_t == INF) cout << -1;
	else cout << min_t;

	return 0;
}