#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 1e9
using namespace std;

int T, N;
int file[501], sum[501];
int dp[501][501];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> T;
	
	while (T--) {
		memset(sum, 0, sizeof(sum));
		memset(dp, 0, sizeof(dp));
		
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> file[i];
			sum[i] = sum[i - 1] + file[i];
		}

		for (int i = 1; i < N; i++) {
			for (int j = 1; i + j <= N; j++) {
				dp[j][i + j] = INF;
				for (int k = j; k < i + j; k++)
					dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + sum[i + j] - sum[j - 1]);
			}
		}

		cout << dp[1][N] << "\n";
	}

	return 0;
}