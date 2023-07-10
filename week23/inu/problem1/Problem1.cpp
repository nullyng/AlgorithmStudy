#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

const int MAX = 500000;
bool checked[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	string number;

	cin >> N >> K;
	cin >> number;

	int i = 1;
	stack<char> st;

	st.push(number[0]);

	for (; i < N; i++) {
		if (K <= 0) break;

		while (!st.empty() && st.top() < number[i]) {
			st.pop();
			K--;
			if (K <= 0) break;
		}

		st.push(number[i]);
	}

	string maxNumber;

	if (K != 0) {
		while (K > 0) {
			st.pop();
			K--;
		}
	}

	while (!st.empty()) {
		maxNumber += st.top();
		st.pop();
	}

	reverse(maxNumber.begin(), maxNumber.end());

	for (; i < N; i++) {
		maxNumber += number[i];
	}

	cout << maxNumber;

	return 0;
}