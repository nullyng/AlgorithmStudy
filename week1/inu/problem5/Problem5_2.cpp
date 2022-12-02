#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

int solution(string s) {
	int cnt = 0;
	int len = (int)s.length();
	unordered_map<char, char> bracket;

	bracket.insert({ '(', ')' });
	bracket.insert({ '[', ']' });
	bracket.insert({ '{', '}' });

	for (int i = 0; i < len; i++) {
		bool flag = true;
		stack<char> st;

		for (int j = i; j < i + len; j++) {
			int idx = j % len;
			char c = s[idx];

			if (c == '(' || c == '[' || c == '{') {
				st.push(c);
			}
			else if (st.empty() 
				|| (*bracket.find(st.top())).second != c) {
				flag = false;
				break;
			}
			else {
				st.pop();
			}
		}

		if (flag && st.empty())
			cnt++;
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	int cnt = 0;

	cin >> s;

	cout << solution(s);

	return 0;
}