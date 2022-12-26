#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> S;

char moo(int k, int N) {
	if (k == 0) {
		if (N == 1) return 'm';
		else return 'o';
	}

	if (N >= 1 && N <= S[k - 1]) {
		return moo(k - 1, N);
	}
	else if (N > S[k - 1]
		&& N < (S[k - 1] + 1) + (k + 3)) {
		N -= S[k - 1];
		if (N == 1) return 'm';
		else return 'o';
	}
	else {
		return moo(k - 1, N - S[k - 1] - (k + 3));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	int k = 0;
	S.push_back(3);

	while (1) {
		if (S[k] >= N)
			break;

		k++;
		S.push_back(2 * S[k - 1] + (1 + k + 2));
	}

	cout << moo(k, N);

	return 0;
}