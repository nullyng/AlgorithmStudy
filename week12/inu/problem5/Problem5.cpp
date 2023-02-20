#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int ALPHABET = 26;
int N;
int capital[ALPHABET];

bool compare(pair<int, char> p1, pair<int, char> p2) {
	if (p1.first == p2.first)
		return p1.second < p2.second;
	return p1.first > p2.first;
}

void toPri(string s) {
	int digit = 1;
	int len = (int)s.length() - 1;
	int i = len;

	while (i >= 0) {
		int idx = s[i] - 'A';
		capital[idx] += digit;
		digit *= 10;
		i--;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		toPri(s);
	}

	sort(capital, capital + 26, greater<>());

	int idx = 0;
	int result = 0;
	int n = 9;

	while (1) {
		if (idx >= 10 || !capital[idx])
			break;

		result += capital[idx] * n;
		n--;
		idx++;
	}

	cout << result;

	return 0;
}