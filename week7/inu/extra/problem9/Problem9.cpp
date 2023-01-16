#include <iostream>
#include <vector>
#include <queue>
#define INF INT32_MAX

using namespace std;

typedef struct edge {
	int v, k;
}edge;

int n, m;
int parent[101];
bool reachable[101];
vector<int> upper;
vector<int> rev[101];
vector<edge> graph[101];

void checkPath() {
	queue<int> q;

	q.push(n);
	reachable[n] = true;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v : rev[u]) {
			if (!reachable[v]) {
				q.push(v);
				reachable[v] = true;
			}
		}
	}
}

vector<int> bellmanFord(int src) {
	vector<int> upper(n + 1, INF);
	upper[src] = 0;

	for (int i = 0; i < n - 1; i++) {
		for (int u = 1; u <= n; u++) {
			if (upper[u] == INF)
				continue;

			for (int cur = 0; cur < (int)graph[u].size(); cur++) {
				edge e = graph[u][cur];
				if (upper[e.v] > upper[u] + e.k) {
					upper[e.v] = upper[u] + e.k;
					parent[e.v] = u;
				}
			}
		}
	}

	for (int u = 1; u <= n; u++) {
		if (upper[u] == INF)
			continue;

		for (int cur = 0; cur < (int)graph[u].size(); cur++) {
			edge e = graph[u][cur];
			if (upper[e.v] > upper[u] + e.k) {
				// 도착점에서 음수 사이클까지 도달 가능
				if (reachable[e.v]) {
					upper.clear();
					return upper;
				}
			}
		}
	}

	return upper;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int u, v, k;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> u >> v >> k;
		graph[u].push_back({ v, -k });
		rev[v].push_back(u);
	}

	// 도착점에서 다른 정점까지의 경로가 있는지 체크
	checkPath();

	// 시작점에서 도착점까지 연결이 안된 경우
	if (!reachable[1]) {
		cout << -1;
		return 0;
	}

	upper = bellmanFord(1);

	// 경로에 음수 사이클이 포함된 경우
	if (upper.empty()) {
		cout << -1;
	}
	else {
		vector<int> ans;
		int cur = n;
		
		while (cur != 0) {
			ans.push_back(cur);
			cur = parent[cur];
		}

		for (int i = (int)ans.size() - 1; i >= 0; i--)
			cout << ans[i] << ' ';
	}

	return 0;
}