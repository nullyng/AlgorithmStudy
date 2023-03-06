#include <iostream>
#include <set>
#define INF 100001

using namespace std;

int N, K;
int dp[100001];
set<int> coin;

int findMinCnt(int value) {
	int cnt = INF;

	for (set<int>::iterator it = coin.begin(); it != coin.end(); it++) {
		if (*it > value) break;
		
		int idx = value - *it;
		if (dp[idx]) cnt = min(cnt, dp[idx]);
	}

	if (cnt == INF) cnt = 0;
	else cnt++;

	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int value;
		cin >> value;
		dp[value] = 1;
		coin.insert(value);
	}

	int min_value = *(coin.begin());

	for (int i = min_value; i <= K; i++) {
		if (dp[i] == 1) continue;
		dp[i] = findMinCnt(i);
	}

	if (dp[K] == 0)
		dp[K] = -1;

	cout << dp[K];

	return 0;
}