#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <string.h>

using namespace std;

bool print[200];
string s;
vector<pair<int, int>> brackets;
set<string> str_set;

void findExp(int depth) {
	if (depth >= (int)brackets.size()) {
		string temp = "";

		for (int i = 0; i < (int)s.size(); i++) {
			if (print[i])
				temp += s[i];
		}

		if (s.compare(temp)) {
			str_set.insert(temp);
		}

		return;
	}

	print[brackets[depth].first] = true;
	print[brackets[depth].second] = true;
	findExp(depth + 1);

	print[brackets[depth].first] = false;
	print[brackets[depth].second] = false;
	findExp(depth + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	stack<int> st;

	cin >> s;

	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == '(') {
			st.push(i);
		}
		else if (s[i] == ')') {
			brackets.push_back({ st.top(), i });
			st.pop();
		}
	}

	memset(print, 1, sizeof(bool) * 200);

	findExp(0);

	set<string>::iterator iter;

	for (iter = str_set.begin(); iter != str_set.end(); iter++) {
		cout << *iter << '\n';
	}

	return 0;
}