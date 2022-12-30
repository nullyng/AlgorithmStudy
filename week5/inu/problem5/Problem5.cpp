#include <iostream>

using namespace std;

int tile[31];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;

	cin >> N;

	tile[0] = 1;
	tile[2] = 3;

	for (int i = 4; i <= N; i += 2) {
		tile[i] = 3 * tile[i - 2];

		for (int j = 4; j <= i; j += 2) {
			tile[i] += 2 * tile[i - j];
		}
	}

	cout << tile[N];

	return 0;
}