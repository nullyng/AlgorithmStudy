#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	stack<char> st;

	cin >> s;

	if (s[0] != 'A') {
		for (int i = 0; i < (int)s.length(); i++) {
			st.push(s[i]);
			
			if ((int)st.size() >= 4) {
				string temp = "";
				int cnt = 0;

				while (cnt < 4) {
					temp += st.top();
					st.pop();
					cnt++;
				}

				if (temp == "PAPP") st.push('P');
				else {
					for (int i = 3; i >= 0; i--)
						st.push(temp[i]);
				}
			}
		}
	}

	if (st.size() == 1) cout << "PPAP";
	else cout << "NP";

	return 0;
}