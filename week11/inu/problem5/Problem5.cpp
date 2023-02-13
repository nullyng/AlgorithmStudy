#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct pos {
	int x, y;
}pos;

int N;
int map[100][100];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
bool visited[100][100];
vector<vector<pos>> lands;

void BFS(int i, int j) {
	vector<pos> land;
	queue<pos> q;

	visited[i][j] = true;
	q.push({ i, j });
	land.push_back({ i, j });

	while (!q.empty()) {
		pos p = q.front();
		q.pop();

		for (int d = 0; d < 4; d++) {
			int x = p.x + dx[d];
			int y = p.y + dy[d];

			if (x < 0 || x >= N || y < 0 || y >= N)
				continue;

			if (map[x][y] && !visited[x][y]) {
				visited[x][y] = true;
				q.push({ x, y });
				land.push_back({ x, y });
			}
		}
	}

	lands.push_back(land);
}

int connect(vector<pos> l1, vector<pos> l2) {
	int min_len = 200;

	for (int i = 0; i < (int)l1.size(); i++) {
		for (int j = 0; j < (int)l2.size(); j++) {
			int len = abs(l1[i].x - l2[j].x) + abs(l1[i].y - l2[j].y);
			min_len = min(min_len, len - 1);
		}
	}

	return min_len;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			if (map[i][j] && !visited[i][j]) {
				BFS(i, j);
			}

	int min_len = 200;

	for (int i = 0; i < (int)lands.size() - 1; i++) {
		for (int j = i + 1; j < (int)lands.size(); j++) {
			min_len = min(min_len, connect(lands[i], lands[j]));
		}
	}

	cout << min_len;

	return 0;
}