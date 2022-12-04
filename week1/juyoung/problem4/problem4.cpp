#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	string str;
	regex re("(100+1+|01)+");

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> str;
		if (regex_match(str, re)) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}