#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000001

using namespace std;

int N, L, R, X;
int level[15];
int result = 0;

void comb(int i, vector<int> v, int sum) {
	if (i >= N) {
		int cnt = (int)v.size();

		if (cnt < 2 || sum < L || sum > R)
			return;

		sort(v.begin(), v.end());

		if (v[cnt - 1] - v[0] >= X)
			result++;

		return;
	}

	v.push_back(level[i]);
	comb(i + 1, v, sum + level[i]);

	v.pop_back();
	comb(i + 1, v, sum);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> L >> R >> X;

	if (N < 2) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < N; i++) {
		cin >> level[i];
	}

	comb(0, vector<int>(), 0);

	cout << result;

	return 0;
}