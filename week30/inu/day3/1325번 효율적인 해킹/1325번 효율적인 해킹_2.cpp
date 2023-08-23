#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 10001;

int N, M;
int answer = 0;
vector<int> graph[MAX];
vector<int> hacked;

int BFS(int n) {
	bool visited[MAX] = { false, };
	queue<int> q;
	int cnt = 1;

	visited[n] = true;
	q.push(n);

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v : graph[u]) {
			if (!visited[v]) {
				visited[v] = true;
				cnt++;
				q.push(v);
			}
		}
	}

	return cnt;
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
		int cnt = BFS(i);

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