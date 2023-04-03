#include <iostream>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	map<int, int> m;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int s, t;
		cin >> s >> t;
		m[s]++;
		m[t]--;
	}

	int sum = 0;
	int maxSum = 0;

	for (auto inst : m) {
		sum += inst.second;
		maxSum = max(maxSum, sum);
	}

	cout << maxSum;

	return 0;
}