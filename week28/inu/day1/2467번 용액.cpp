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

	int l = 0, r = N - 1;
	int value = 2000000001;
	pair<int, int> comb;

	while (l < r) {
		int mix = liquid[l] + liquid[r];

		if (abs(mix) < value) {
			value = abs(mix);
			comb.first = liquid[l];
			comb.second = liquid[r];
		}

		if (mix < 0) l++;
		else if (mix > 0) r--;
		else break;
	}

	cout << comb.first << ' ' << comb.second;

	return 0;
}