#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

typedef struct pos {
	float x, y;
}pos;

typedef struct edge {
	int u, v;
	float d;
}edge;

int N;
int parent[100];
vector<edge> edges;

bool compare(edge e1, edge e2) {
	return e1.d < e2.d;
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

	parent[u] = v;
}

float MST() {
	for (int i = 0; i < N; i++)
		parent[i] = i;

	sort(edges.begin(), edges.end(), compare);

	int cnt = 0;
	float cost = 0;

	for (edge e : edges) {
		int u = Find(e.u, e.u);
		int v = Find(e.v, e.v);

		if (u == v) continue;

		Union(u, v);
		cost += e.d;
		cnt++;

		if (cnt == N - 1)
			break;
	}

	return cost;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	vector<pos> stars;

	for (int i = 0; i < N; i++) {
		float x, y;
		cin >> x >> y;
		stars.push_back({ x, y });
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			float x = abs(stars[i].x - stars[j].x);
			float y = abs(stars[i].y - stars[j].y);
			float d = sqrtf(x * x + y * y);
			edges.push_back({i, j, d});
		}
	}

	cout << MST();

	return 0;
}