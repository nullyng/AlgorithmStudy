#include <iostream>
#include <vector>
#define INF 1000000

using namespace std;

int N, K, S;
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

	cin >> N >> K;

	graph.assign(N + 1, vector<int>(N + 1, INF));

	int a, b;

	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		graph[a][b] = 1;
	}

	floyd();

	cin >> S;

	for (int i = 0; i < S; i++) {
		int result = 0;

		cin >> a >> b;
		
		if (graph[a][b] != INF) {
			result = -1;
		}
		else if (graph[b][a] != INF) {
			result = 1;
		}
		else {
			result = 0;
		}

		cout << result << '\n';
	}

	return 0;
}