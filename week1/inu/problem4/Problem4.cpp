#include <iostream>
#include <regex>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	string str;
	regex re("(100+1+|01)+");

	cin >> N;

	while (N) {
		cin >> str;

		if (regex_match(str, re)) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}

		N--;
	}

	return 0;
}