#include <iostream>

using namespace std;

int parent[1000001];
int height[1000001];

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
	u = Find(u, u);
	v = Find(v, v);

	if (u != v) {
		if (height[u] > height[v])
			swap(u, v);

		parent[u] = v;

		if (height[u] == height[v])
			height[v]++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int c, a, b;

	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
		height[i] = 1;
	}

	for (int i = 0; i < m; i++) {
		cin >> c >> a >> b;

		if (c == 0) {
			Union(a, b);
		}
		else {
			if (Find(a, a) == Find(b, b))
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
	}

	return 0;
}