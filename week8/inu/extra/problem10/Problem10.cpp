#include <iostream>
#include <vector>
#define INF 10000

using namespace std;

int N, M;
int inout[501];
vector<vector<int>> graph;

void floyd() {
	for (int i = 1; i <= N; i++)
		graph[i][i] = 0;

	for(int k = 1; k <= N; k++)
		for (int u = 1; u <= N; u++) {
			if (graph[u][k] == INF)
				continue;

			for (int v = 1; v <= N; v++)
				graph[u][v] = min(graph[u][v], graph[u][k] + graph[k][v]);
		}	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	int a, b;

	graph.assign(N + 1, vector<int>(N + 1, INF));

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a][b] = 1;
	}

	floyd();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)
				continue;

			if (graph[i][j] && graph[i][j] != INF) {
				inout[i]++;
				inout[j]++;
			}
		}
	}

	int cnt = 0;

	for (int i = 1; i <= N; i++)
		if (inout[i] == N - 1)
			cnt++;

	cout << cnt;

	return 0;
}