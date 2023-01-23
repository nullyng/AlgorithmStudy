#include <iostream>
#include <vector>
#include <algorithm>
#define INF INT32_MAX

using namespace std;

int N, M;
int parent[101];
int height[101];
vector<vector<int>> graph;
vector<int> committee[101];

void swap(int& u, int& v) {
	int temp = u;
	u = v;
	v = temp;
}

int Find(int u, int origin) {
	if (u == parent[u]) {
		parent[origin] = u;
		return u;
	}

	return Find(parent[u], origin);
}

void Union(int u, int v) {
	u = Find(u, u);
	v = Find(v, v);

	if (height[u] > height[v])
		swap(u, v);

	parent[u] = v;

	if (height[u] == height[v])
		height[v]++;
}

void floyd() {
	for (int i = 1; i <= N; i++)
		graph[i][i] = 0;

	for(int k = 1; k <= N; k++)
		for (int u = 1; u <= N; u++) {
			if (graph[u][k] == INF) continue;

			for (int v = 1; v <= N; v++) {
				if (graph[k][v] == INF) continue;
				graph[u][v] = min(graph[u][v], graph[u][k] + graph[k][v]);
			}
		}		
}

int getRep(vector<int> sub) {
	int len = (int)sub.size();
	int min_time = INF;
	int rep = 0;

	for (int i = 0; i < len; i++) {
		int time = 0;

		for (int j = 0; j < len; j++) {
			time = max(time, graph[sub[i]][sub[j]]);
		}

		if (time < min_time) {
			rep = sub[i];
			min_time = time;
		}
	}
		
	return rep;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	graph.assign(N + 1, vector<int>(N + 1, INF));

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		height[i] = 1;
	}

	int u, v;

	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		graph[u][v] = 1;
		graph[v][u] = 1;
		Union(u, v);
	}

	floyd();

	int K = 0, p = 0;
	vector<int> reps;

	for (int i = 1; i <= N; i++) {
		if (parent[i] == i) {
			K++;
			p = i;
		}
		else {
			p = Find(i, i);
		}

		committee[p].push_back(i);
	}

	for (int i = 1; i <= N; i++) {
		if (committee[i].empty())
			continue;

		int rep = getRep(committee[i]);
		reps.push_back(rep);
	}
	sort(reps.begin(), reps.end());

	cout << K << '\n';

	for (int rep : reps)
		cout << rep << '\n';

	return 0;
}