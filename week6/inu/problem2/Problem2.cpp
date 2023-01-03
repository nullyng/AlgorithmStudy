#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct edge {
	int h1, h2, k;
}edge;

int N, M;
int s, e;
int parent[100001];
int height[100001];
vector<edge> graph;

bool compare(edge b1, edge b2) {
	return b1.k > b2.k;
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

	cin >> N >> M >> s >> e;

	int result = 0;
	int h1, h2, k;

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		height[i] = 1;
	}

	for (int i = 0; i < M; i++) {
		cin >> h1 >> h2 >> k;
		graph.push_back({ h1, h2, k });
	}

	sort(graph.begin(), graph.end(), compare);

	for (edge ed : graph) {
		h1 = ed.h1;
		h2 = ed.h2;

		if (Find(h1, h1) == Find(h2, h2))
			continue;

		Union(h1, h2);

		if (Find(s, s) == Find(e, e)) {
			result = ed.k;
			break;
		}
	}

	cout << result;

	return 0;
}