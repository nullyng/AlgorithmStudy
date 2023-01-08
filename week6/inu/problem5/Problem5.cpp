#include <iostream>

using namespace std;

int N, M, k;
int cost[10001];
int parent[10001];

void swap(int& u, int& v) {
	int temp = u;
	u = v;
	v = temp;
}

int Find(int u, int origin) {
	if (parent[u] == u) {
		parent[origin] = u;
		return u;
	}

	return Find(parent[u], origin);
}

void Union(int u, int v) {
	if (cost[u] < cost[v])
		swap(u, v);

	parent[u] = v;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> k;

	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
		parent[i] = i;
	}

	int u, v;
	int result = 0;
	bool flag = true;

	for (int i = 0; i < M; i++) {
		cin >> u >> v;

		u = Find(u, u);
		v = Find(v, v);

		if (u != v) {
			Union(u, v);
		}
	}

	for (int i = 1; i <= N; i++) {
		if (parent[i] != i) 
			continue;

		result += cost[i];

		if (result > k) {
			flag = false;
			break;
		}
	}

	if (flag)
		cout << result;
	else
		cout << "Oh no";

	return 0;
}