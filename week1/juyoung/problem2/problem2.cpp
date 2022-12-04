#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str, bomb, answer;
	cin >> str >> bomb;

	int len = bomb.length();
	for (int i = 0; i < str.length(); i++) {
		answer += str[i];
		if (str[i] == bomb[len - 1] && answer.length() >= bomb.length()) {
			string temp = answer.substr(answer.length() - len, len);
			if (temp == bomb) {
				for (int j = 0; j < len; j++) answer.pop_back();
			}
		}
	}

	if (answer.length() <= 0) cout << "FRULA\n";
	else cout << answer << "\n";

	return 0;
}