#include <iostream>
#include <vector>
#define INF 10000000

using namespace std;

int N, M, R;
int item[101];
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

	cin >> N >> M >> R;

	int a, b, l;

	graph.assign(N + 1, vector<int>(N + 1, INF));

	for (int i = 1; i <= N; i++)
		cin >> item[i];

	for (int i = 0; i < R; i++) {
		cin >> a >> b >> l;
		graph[a][b] = l;
		graph[b][a] = l;
	}

	floyd();

	int max_item = 0;

	for (int k = 1; k <= N; k++) {
		int item_sum = 0;

		for (int i = 1; i <= N; i++) {
			if (graph[k][i] > M)
				continue;

			item_sum += item[i];
		}

		max_item = max(max_item, item_sum);
	}

	cout << max_item;

	return 0;
}