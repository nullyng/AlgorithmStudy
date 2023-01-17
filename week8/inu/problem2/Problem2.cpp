#include <iostream>
#include <vector>
#define INF 10000000

using namespace std;

int N, M;
int b1, b2;
int minTime = INF;
vector<vector<int>> graph;

void floyd() {
	for (int i = 1; i <= N; i++)
		graph[i][i] = 0;

	for(int k = 1; k <= N; k++)
		for (int u = 1; u <= N; u++) {
			if (graph[u][k] == INF) 
				continue;

			for (int v = 1; v <= N; v++) {
				graph[u][v] = min(graph[u][v], graph[u][k] + graph[k][v]);
			}
		}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	graph.assign(N + 1, vector<int>(N + 1, INF));

	int a, b;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	floyd();
	
	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j <= N; j++) {
			int sum = 0;

			for (int k = 1; k <= N; k++)
				sum += min(graph[k][i], graph[k][j]);

			if (sum < minTime) {
				minTime = sum;
				b1 = i;
				b2 = j;
			}
		}
	}

	cout << b1 << ' ';
	cout << b2 << ' ';
	cout << minTime * 2;

	return 0;
}