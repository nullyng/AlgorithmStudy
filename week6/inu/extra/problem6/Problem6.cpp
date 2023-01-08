#include <iostream>

using namespace std;

int G, P;
int gate[100001];

int Find(int u, int origin) {
	if (gate[u] == u) {
		gate[origin] = u;
		return u;
	}

	return Find(gate[u], origin);
}

void Union(int u, int v) {
	u = Find(u, u);
	v = Find(v, v);

	if (u != v)
		gate[u] = v;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int u;
	int result = 0;

	cin >> G >> P;

	for (int i = 1; i <= G; i++)
		gate[i] = i;

	for (int i = 0; i < P; i++) {
		cin >> u;

		if (Find(u, u) == 0)
			break;

		if (gate[u] == u)
			Union(u, u - 1);
		else
			Union(gate[u], gate[u] - 1);

		result++;
	}

	cout << result;

	return 0;
}