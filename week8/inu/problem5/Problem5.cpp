#include <iostream>
#include <vector>
#include <algorithm>
#define INF 100000

using namespace std;

typedef pair<int, int> pii;

int N;
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

	cin >> N;

	graph.assign(N + 1, vector<int>(N + 1, INF));

	int a, b;

	while (1) {
		cin >> a >> b;

		if (a == -1)
			break;

		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	floyd();

	int min_score = INF;
	vector<int> members;

	for (int i = 1; i <= N; i++) {
		int score = 0;

		for (int j = 1; j <= N; j++)
			score = max(score, graph[i][j]);

		if (score < min_score) {
			min_score = score;
			members.clear();
			members.push_back(i);
		}
		else if (score == min_score) {
			members.push_back(i);
		}
	}

	sort(members.begin(), members.end());

	cout << min_score << ' ' << members.size() << '\n';


	for (int member : members)
		cout << member << ' ';

	return 0;
}