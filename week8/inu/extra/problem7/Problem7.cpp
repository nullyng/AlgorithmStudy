#include <iostream>
#include <vector>
#define INF 1000000
using namespace std;

int N;
vector<vector<int>> graph;

bool floyd() {
	for (int k = 1; k <= N; k++) {
		for (int u = 1; u <= N; u++) {
			if (k == u) 
				continue;

			for (int v = 1; v <= N; v++) {
				if (k == v || u == v)
					continue;

				if (graph[u][v] > graph[u][k] + graph[k][v] && graph[u][v] != INF) {
					return false;
				}
				else if (graph[u][v] == graph[u][k] + graph[k][v]) {
					graph[u][v] = INF;
				}
			}
		}	
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	graph.assign(N + 1, vector<int>(N + 1, 0));

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> graph[i][j];

	int sum = 0;

	if (floyd()) {
		for (int i = 1; i < N; i++)
			for (int j = i + 1; j <= N; j++)
				if (graph[i][j] != INF)
					sum += graph[i][j];
	}
	else {
		sum = -1;
	}

	cout << sum;

	return 0;
}