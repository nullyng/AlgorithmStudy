#include <iostream>
#include <map>
#include <set>

using namespace std;

map<int, int> problems;
set<pair<int, int>, greater<pair<int, int>>> ordered;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int p, l;

		cin >> p >> l;

		problems[p] = l;
		ordered.insert({ l, p });
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		string command;

		cin >> command;

		if (command.compare("recommend") == 0) {
			int n;
			cin >> n;

			if (n == 1) {
				cout << ordered.begin()->second << '\n';
			}
			else {
				cout << ordered.rbegin()->second << '\n';
			}
		}
		else if (command.compare("add") == 0) {
			int p, l;
			cin >> p >> l;
			problems[p] = l;
			ordered.insert({ l, p });
		}
		else {
			int p, l;
			cin >> p;
			l = problems[p];
			ordered.erase({ l, p });
			problems.erase(p);
		}
	}

	return 0;
}