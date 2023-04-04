#include <iostream>
#include <vector>

#define MAX 3000

using namespace std;

typedef struct info {
	int x, y, r;
}info;

int parent[MAX];

int Find(int u) {
	if (parent[u] == u) return u;
	return parent[u] = Find(parent[u]);
}

void Union(int u, int v) {
	u = Find(u);
	v = Find(v);

	if (u != v) parent[u] = v;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;

	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		vector<info> c;
		
		cin >> N;

		for (int i = 0; i < N; i++) {
			int x, y, r;
			cin >> x >> y >> r;
			c.push_back({ x, y ,r });
			parent[i] = i;
		}

		int ans = N;

		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				if (Find(i) != Find(j)) {
					int dx = c[i].x - c[j].x;
					int dy = c[i].y - c[j].y;
					int dr = c[i].r + c[j].r;

					if (dr * dr >= dx * dx + dy * dy) {
						Union(i, j);
						ans--;
					}
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}