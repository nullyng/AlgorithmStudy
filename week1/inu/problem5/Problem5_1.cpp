#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	int len;
	int cnt = 0;

	cin >> s;

	len = (int)s.length();

	for (int i = 0; i < len; i++) {
		bool flag = true;
		stack<char> st;

		for (int j = i; j < i + len; j++) {
			int idx = j % len;
			char c = s[idx];
			
			if (c == '(' || c == '[' || c == '{') {
				st.push(c);
				continue;
			}
			
			if (st.empty()) {
				flag = false;
			}
			else {
				char top = st.top();

				switch (c) {
				case ')':
					if (top != '(')
						flag = false;
					else
						st.pop();
					break;
				case ']':
					if (top != '[')
						flag = false;
					else
						st.pop();
					break;
				case '}':
					if (top != '{')
						flag = false;
					else
						st.pop();
					break;
				}
			}

			if (!flag)
				break;
		}

		if (flag && st.empty())
			cnt++;
	}

	cout << cnt;

	return 0;
}