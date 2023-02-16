#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	int neg = 0;
	int pos = 0;
	bool zero = false;
	int answer = 0;
	vector<int> seq;

	cin >> N;
	seq.assign(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> seq[i];
		if (seq[i] > 0) pos++;
		else if (seq[i] < 0) neg++;
		else zero = true;
	}	

	sort(seq.begin(), seq.end());

	int idx = 0;

	while (neg > 1) {
		answer += seq[idx] * seq[idx + 1];
		idx += 2;
		neg -= 2;
	}

	if (neg == 1 && !zero) {
		answer += seq[idx];
	}

	idx = N - 1;

	while (pos > 1) {
		int p1 = seq[idx];
		int p2 = seq[idx - 1];

		if (p1 == 1 || p2 == 1) {
			answer += p1;
			answer += p2;
		}
		else {
			answer += p1 * p2;
		}

		idx -= 2;
		pos -= 2;
	}

	if (pos == 1) {
		answer += seq[idx];
	}

	cout << answer;

	return 0;
}