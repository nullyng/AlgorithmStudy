#include <iostream>

using namespace std;

const int MAX = 100000;

int N;
int liquid[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> liquid[i];
	}

	int s = 0;
	int e = N - 1;
	pair<int, int> comb;
	int ans = 2000000001;

	while (s < e) {
		int mix = abs(liquid[s] + liquid[e]);

		if (mix < ans) {
			ans = mix;
			comb.first = liquid[s];
			comb.second = liquid[e];
		}

		s++;
		e--;
	}

	if (s == e) {
		if (abs(liquid[s - 1] + liquid[s]) < ans) {
			ans = abs(liquid[s - 1] + liquid[s]);
			comb.first = liquid[s - 1];
			comb.second = liquid[s];
		}

		if (abs(liquid[s] + liquid[s + 1]) < ans) {
			ans = abs(liquid[s] + liquid[s + 1]);
			comb.first = liquid[s];
			comb.second = liquid[s + 1];
		}
	}

	cout << comb.first << ' ' << comb.second;

	return 0;
}