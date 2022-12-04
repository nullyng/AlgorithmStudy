#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string origin, word;
	string remain = "";
	int origin_len, word_len;
	
	cin >> origin >> word;

	origin_len = (int)origin.length();
	word_len = (int)word.length();

	for (int i = 0; i < origin_len; i++) {
		remain += origin[i];

		if (remain.length() < word_len) 
			continue;

		bool flag = true;
		int len = (int)remain.length();

		for (int j = 0; j < word_len; j++) {
			if (remain[len - word_len + j] != word[j]) {
				flag = false;
				break;
			}
		}

		if (flag) {
			int cnt = word_len;

			while (cnt) {
				remain.pop_back();
				cnt--;
			}
		}
	}

	if (remain.length() == 0) {
		remain = "FRULA";
	}

	cout << remain;

	return 0;
}