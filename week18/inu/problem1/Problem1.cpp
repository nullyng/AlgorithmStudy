#include <iostream>
#include <vector>

#define MAX 300001

using namespace std;

int parent[MAX];
int height[MAX];

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

	int N;

	cin >> N;

	for (int i = 1; i <= N; i++)
		parent[i] = i;

	for (int i = 0; i < N - 2; i++) {
		int u, v;
		cin >> u >> v;
		Union(u, v);
	}

	vector<int> node;

	for (int i = 1; i <= N; i++) {
		if (parent[i] == i)
			node.push_back(i);

		if ((int)node.size() == 2) break;
	}

	for (int n : node)
		cout << n << ' ';

	return 0;
}