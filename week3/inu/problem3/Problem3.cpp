#include <iostream>
#include <vector>

using namespace std;

int N;
vector<string> v;

void decrease(string s, char end, int len) {
	if (end < '0' || end > '9') return;

	if ((int)s.size() == len) {
		v.push_back(s);
		return;
	}

	for (char c = '0'; c < end; c++) {
		s += c;
		decrease(s, c, len);
		s.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;

	for (int len = 1; len <= 10; len++) {
		for (char c = '0'; c <= '9'; c++) {
			string s = "";
			s += c;
			decrease(s, c, len);
		}
	}

	if (N >= (int)v.size()) {
		cout << -1;
	}
	else {
		cout << v[N];
	}

	return 0;
}