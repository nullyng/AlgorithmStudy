#include <iostream>

using namespace std;

int M, N;
int map[500][500];
int dp[500][500];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int DFS(int x, int y) {
	if (x == M - 1 && y == N - 1) return 1;
	if (dp[x][y] != -1) return dp[x][y];

	dp[x][y] = 0;

	for (int d = 0; d < 4; d++) {
		int rx = x + dx[d];
		int ry = y + dy[d];

		if (rx < 0 || rx >= M || rx < 0 || ry >= N)
			continue;

		if (map[rx][ry] < map[x][y]) {
			dp[x][y] += DFS(rx, ry);
		}
	}

	return dp[x][y];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N;

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}
			
	cout << DFS(0, 0);

	return 0;
}