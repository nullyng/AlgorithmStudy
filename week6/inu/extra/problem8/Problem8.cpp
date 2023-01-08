#include <iostream>
#include <unordered_map>

using namespace std;

typedef unordered_map<string, int> um;

int parent[200001];
int height[200001];

void init(int F) {
	for (int i = 1; i <= F * 2; i++) {
		parent[i] = i;
		height[i] = 1;
	}
}

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

int Union(int u, int v) {
	u = Find(u, u);
	v = Find(v, v);

	if (u != v) {
		if (height[u] > height[v])
			swap(u, v);

		parent[u] = v;
		height[v] += height[u];
	}

	int result = max(height[u], height[v]);

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T, F;
	string f1, f2;

	cin >> T;

	for (int i = 0; i < T; i++) {
		int idx = 1;
		int u, v;
		um network;

		cin >> F;

		init(F);

		for (int j = 0; j < F; j++) {
			cin >> f1 >> f2;

			if (network.find(f1) == network.end()) {
				network[f1] = idx;
				idx++;
			}

			if (network.find(f2) == network.end()) {
				network[f2] = idx;
				idx++;
			}

			u = network[f1];
			v = network[f2];

			cout << Union(u, v) << '\n';
		}
	}

	return 0;
}