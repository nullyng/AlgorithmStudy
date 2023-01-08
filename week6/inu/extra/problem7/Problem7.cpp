#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct edge {
	int u, v, k;
}edge;

int parent[10001];
int height[10001];
vector<edge> graph;

bool compare(edge e1, edge e2) {
	return e1.k > e2.k;
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

	int N, M;
	int u, v, k;
	int S, E;
	int result = 0;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		height[i] = 1;
	}

	for (int i = 0; i < M; i++) {
		cin >> u >> v >> k;
		graph.push_back({ u, v, k });
	}

	sort(graph.begin(), graph.end(), compare);

	cin >> S >> E;

	for (const edge& e : graph) {
		u = Find(e.u, e.u);
		v = Find(e.v, e.v);

		if (u != v) {
			Union(u, v);

			if (Find(S, S) == Find(E, E)) {
				result = e.k;
				break;
			}
		}
	}

	cout << result;

	return 0;
}