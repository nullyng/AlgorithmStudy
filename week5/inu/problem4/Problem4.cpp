#include <iostream>
#define MOD 1000000003

using namespace std;

int dp[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;

	cin >> N >> K;

	if (K > N / 2) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i <= N; i++)
		dp[i][0] = 1;
	
	dp[1][1] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
		}
	}

	dp[N][K] = (dp[N - 3][K - 1] + dp[N - 1][K]) % MOD;

	cout << dp[N][K];

	return 0;
}