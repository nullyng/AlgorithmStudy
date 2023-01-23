#include <iostream>
#include <vector>
#define INF 10000000

using namespace std;

typedef pair<int, int> pii;

int N, M, T;
bool teleport[1001];
vector<pii> city;
vector<vector<int>> graph;

void floyd() {
	for (int k = 1; k <= N; k++) {
		for (int u = 1; u <= N; u++) {
			for (int v = 1; v <= N; v++) {
				graph[u][v] = min(graph[u][v], graph[u][k] + graph[k][v]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> T;

	int s, x, y;

	graph.assign(N + 1, vector<int>(N + 1, INF));
	city.assign(N + 1, {0, 0});

	for (int i = 1; i <= N; i++) {
		cin >> s >> x >> y;
		city[i] = { x, y };
		
		if (s == 1) {
			teleport[i] = true;
		}
	}

	for (int u = 1; u < N; u++) {
		int ux = city[u].first;
		int uy = city[u].second;

		for (int v = u + 1; v <= N; v++) {
			int vx = city[v].first;
			int vy = city[v].second;
			int uv = abs(ux - vx) + abs(uy - vy);

			if (teleport[u] && teleport[v]) {
				uv = min(uv, T);
			}

			graph[u][v] = uv;
			graph[v][u] = uv;
		}
	}

	floyd();

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		cout << graph[x][y] << '\n';
	}

	return 0;
}