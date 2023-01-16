#include <iostream>
#include <vector>
#define INF INT32_MAX

using namespace std;

int V, E;
vector<vector<int>> graph;

void floyd() {
	for (int k = 1; k <= V; k++)
		for (int u = 1; u <= V; u++)
			if (graph[u][k] != INF) {
				for (int v = 1; v <= V; v++)
					if(graph[k][v] != INF)
						graph[u][v] = 
							min(graph[u][v], graph[u][k] + graph[k][v]);
			}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a, b, c;

	cin >> V >> E;

	graph.assign(V + 1, vector<int>(V + 1, INF));

	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		graph[a][b] = c;
	}

	floyd();
	
	int max_cycle = INF;

	for (int i = 1; i <= V; i++)
		max_cycle = min(max_cycle, graph[i][i]);

	if (max_cycle == INF)
		max_cycle = -1;

	cout << max_cycle;

	return 0;
}