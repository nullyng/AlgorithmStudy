#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	int cnt = 0;
	string str;
	unordered_set<string> s;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> str;
		s.insert(str);
	}

	for (int i = 0; i < M; i++) {
		cin >> str;
		
		if (s.find(str) != s.end()) {
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}