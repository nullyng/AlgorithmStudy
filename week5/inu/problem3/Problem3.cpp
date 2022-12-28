#include <iostream>

using namespace std;

long long tile[2][1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;

	cin >> N;

	tile[0][0] = 0;
	tile[0][1] = 2;
	tile[0][2] = 7;
	tile[1][2] = 1;

	for (int i = 3; i <= N; i++) {
		tile[1][i] = tile[0][i - 3] + tile[1][i - 1];
		tile[0][i] = 2 * tile[0][i - 1] + 3 * tile[0][i - 2] + 2 * tile[1][i];
	}

	cout << tile[0][N];

	return 0;
}