#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

string input;
stack<int> st;
vector<pair<int, int>> bracket;
vector<string> answer;
bool isRemoved[10];

void removeBracket(int cnt) {
	if (cnt == bracket.size()) {
		string changeToX = input;
		for (int i = 0; i < (int)bracket.size(); i++) {
			if (isRemoved[i] == true) {
				changeToX[bracket[i].first] = 'X';
				changeToX[bracket[i].second] = 'X';
			}
		}

		string removed = "";
		for (int i = 0; i < (int)changeToX.length(); i++) {
			if (changeToX[i] == 'X') continue;
			removed += changeToX[i];
		}
		answer.push_back(removed);

		return;
	}

	isRemoved[cnt] = false;
	removeBracket(cnt + 1);
	isRemoved[cnt] = true;
	removeBracket(cnt + 1);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> input;
	for (int i = 0; i < (int)input.length(); i++) {
		if (input[i] == '(') st.push(i);
		else if (input[i] == ')') {
			int index = st.top();
			st.pop();
			bracket.push_back({ index, i });
		}
	}

	removeBracket(0);

	sort(answer.begin(), answer.end());
	answer.erase(unique(answer.begin(), answer.end()), answer.end());

	for (int i = 0; i < (int)answer.size(); i++) {
		if (answer[i] == input) continue;
		cout << answer[i] << "\n";
	}

	return 0;
}