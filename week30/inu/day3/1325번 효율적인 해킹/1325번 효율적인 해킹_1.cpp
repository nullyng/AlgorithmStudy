#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 10001;

int N, M;
int answer = 0;
int cnt = 0;
bool visited[MAX];
vector<int> graph[MAX];
vector<int> hacked;

void DFS(int u) {
	visited[u] = true;
	cnt++;

	for (int v : graph[u]) {
		if (!visited[v])
			DFS(v);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		fill(visited, visited + N + 1, 0);
		cnt = 0;

		DFS(i);

		if (cnt >= answer) {
			if (cnt > answer) {
				answer = cnt;
				hacked.clear();
			}
			hacked.push_back(i);
		}
	}

	for (int u : hacked)
		cout << u << ' ';

	return 0;
}