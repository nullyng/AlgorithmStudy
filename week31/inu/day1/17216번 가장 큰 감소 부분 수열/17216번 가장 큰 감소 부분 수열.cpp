#include <iostream>

using namespace std;

const int MAX = 1000;

int N;
int answer = 0;
int seq[MAX];
int dp[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> seq[i];
		dp[i] = seq[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++)
			if (seq[i] < seq[j])
				dp[i] = max(dp[i], dp[j] + seq[i]);
		answer = max(answer, dp[i]);
	}

	cout << answer;

	return 0;
}