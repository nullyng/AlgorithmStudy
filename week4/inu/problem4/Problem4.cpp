#include <iostream>

using namespace std;

string S, T;

string reverse(string str) {
	string reverse_str = "";

	for (int i = (int)str.size() - 1; i >= 0; i--) {
		reverse_str += str[i];
	}

	return reverse_str;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> S >> T;

	int result = 0;

	while (1) {
		if ((int)T.size() == 0)
			break;

		if (!S.compare(T)) {
			result = 1;
			break;
		}

		if (T.back() == 'A') {
			T.pop_back();
		}
		else {
			T.pop_back();
			T = reverse(T);
		}
	}

	cout << result;

	return 0;
}