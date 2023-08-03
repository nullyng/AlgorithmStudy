#include <iostream>

using namespace std;

const int MAX = 100001;

int C, N;

pair<int, int> city[20]; // ºñ¿ë, °í°´¼ö
int dp[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> C >> N;

	for (int i = 0; i < N; i++)
		cin >> city[i].first >> city[i].second;

	for (int i = 1; i < MAX; i++) {
		for (int j = 0; j < N; j++) {
			int cost = city[j].first;
			int customer = city[j].second;

			if (cost <= i)
				dp[i] = max(dp[i], dp[i - cost] + customer);
		}
	}

	for (int i = 1; i < MAX; i++) {
		if (dp[i] >= C) {
			cout << i;
			break;
		}
	}

	return 0;
}