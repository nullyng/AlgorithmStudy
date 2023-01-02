#include <iostream>
#include <vector>

using namespace std;

int N, M;
int parent[51];
int height[51];
bool truth[51];
vector<vector<int>> party;

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
	if (truth[u] || 
		(!truth[v] && height[u] > height[v]))
		swap(u, v);

	parent[u] = v;

	if (height[u] == height[v])
		height[v]++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	party.assign(M, vector<int>());

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		height[i] = 1;
	}
	
	int n, p;
	int result = M;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> p;
		truth[p] = true;
	}

	for (int i = 0; i < M; i++) {
		int u, v;

		cin >> n;
		cin >> u;

		party[i].push_back(u);

		if (n > 1) {
			for (int j = 1; j < n; j++) {
				cin >> v;
				party[i].push_back(v);

				u = Find(u, u);
				v = Find(v, v);

				if(u != v)
					Union(u, v);
			}
		}
	}

	for (int i = 0; i < M; i++) {
		for (int u : party[i]) {
			if (truth[Find(u, u)]) {
				result--;
				break;
			}
		}
	}

	cout << result;

	return 0;
}