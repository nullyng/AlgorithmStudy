#include <iostream>

using namespace std;

const int ALPHABET = 26;
const int MAX = 200000;

string S;
int q;
int sum[ALPHABET][MAX];

void prefixSum(int cur) {
	if (cur == 0) return;

	for (int i = 0; i < ALPHABET; i++)
		sum[i][cur] += sum[i][cur - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> S >> q;

	for (int i = 0; i < (int)S.size(); i++) {
		sum[S[i] - 'a'][i]++;
		prefixSum(i);
	}

	for (int i = 0; i < q; i++) {
		char c;
		int l, r;
		
		cin >> c >> l >> r;

		if (l == 0) {
			cout << sum[c - 'a'][r] << '\n';
		}
		else {
			cout << sum[c - 'a'][r] - sum[c - 'a'][l - 1] << '\n';
		}
	}

	return 0;
}