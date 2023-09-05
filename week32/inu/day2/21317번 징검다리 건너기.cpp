#include <iostream>

using namespace std;

const int MAX = 999999;

int N, K;
int dp[21][2];
pair<int, int> jump[21];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i < N; i++) {
		cin >> jump[i].first >> jump[i].second;
	}

	cin >> K;

	for (int i = 1; i <= N; i++) {
		dp[i][0] = MAX;
		dp[i][1] = MAX;
	}

	dp[1][0] = 0;
	dp[2][0] = jump[1].first;
	dp[3][0] = min(jump[1].first + jump[2].first, jump[1].second);
	
	for (int i = 4; i <= N; i++) {
		dp[i][0] = min(jump[i - 1].first + dp[i - 1][0], jump[i - 2].second + dp[i - 2][0]);
		dp[i][1] = min(
			min(jump[i - 1].first + dp[i - 1][1], jump[i - 2].second + dp[i - 2][1]),
			dp[i - 3][0] + K);
	}

	int answer = min(dp[N][0], dp[N][1]);

	cout << answer;

	return 0;
}