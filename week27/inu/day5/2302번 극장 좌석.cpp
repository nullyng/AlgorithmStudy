#include <iostream>

using namespace std;

const int MAX = 41;

int vip[MAX];
int dp[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int m;
		cin >> m;
		vip[i] = m;
	}

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	int idx = 1;
	int ans = 1;
	int start = 0;

	for (int i = 0; i < M; i++) {
		ans *= dp[vip[i] - start - 1];
		start = vip[i];
	}

	ans *= dp[N - start];

	cout << ans;

	return 0;
}