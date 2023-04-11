#include <iostream>
#define MAX 1001

using namespace std;

int N, M;
char map[MAX][MAX];
int visited[MAX][MAX];
int result = 0;

int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1 };

int getDir(char c) {
	if (c == 'U') return 0;
	if (c == 'D') return 1;
	if (c == 'L') return 2;
	return 3;
}

void dfs(int i, int j) {
	visited[i][j] = 1;

	int d = getDir(map[i][j]);
	int _i = i + di[d];
	int _j = j + dj[d];

	if (visited[_i][_j] == 1) result++;
	if (visited[_i][_j] == 0) dfs(_i, _j);

	visited[i][j] = 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for(int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			visited[i][j] = 0;
		}		

	for(int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (!visited[i][j]) dfs(i, j);

	cout << result;

	return 0;
}