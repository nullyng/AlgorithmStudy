#include <iostream>

using namespace std;

int N, M;
int parent[201];
int height[201];

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

	if (height[u] > height[v])
		swap(u, v);

	parent[u] = v;

	if (height[u] == height[v])
		height[v]++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int connected;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		height[i] = 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> connected;

			if(i != j && connected) 
				Union(i + 1, j + 1);
		}
	}

	int city, p;
	string isPossible = "YES";

	cin >> city;
	p = Find(city, city);

	for (int i = 1; i < M; i++) {
		cin >> city;
		if (p != Find(city, city)) {
			isPossible = "NO";
			break;
		}
	}

	cout << isPossible;

	return 0;
}