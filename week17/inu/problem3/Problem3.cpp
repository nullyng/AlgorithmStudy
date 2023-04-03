#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;

	cin >> T;

	for (int t = 0; t < T; t++) {
		string word;

		cin >> word;

		int type = 0;
		int s = 0;
		int e = (int)word.length() - 1;

		while (s < e) {
			if (word[s] == word[e]) {
				s++;
				e--;
				continue;
			}

			// abbab와 같은 경우
			if (word[s + 1] == word[e] && word[s] == word[e - 1]) {
				type++;

				// (1) 왼쪽으로 당기기
				int _s = s + 1;
				int _e = e;

				while (_s < _e && word[_s] == word[_e]) {
					_s++;
					_e--;
				}

				// (2) 오른쪽으로 당기기
				if (_s < _e) {
					_s = s;
					_e = e - 1;

					while (_s < _e && word[_s] == word[_e]) {
						_s++;
						_e--;
					}

					if (_s < _e) type++;
				}

				break;
			}

			if (word[s + 1] == word[e]) {
				s++;
				if (type != 2) type++;
				else break;
			}
			else if (word[s] == word[e - 1]) {
				e--;
				if (type != 2) type++;
				else break;
			}
			else {
				type = 2;
				break;
			}
		}

		cout << type << '\n';
	}

	return 0;
}