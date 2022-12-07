#include <iostream>
#include <queue>
#define INF 99999

using namespace std;

typedef struct coin {
	int x, y;
}coin;

typedef struct qData {
	coin c1;
	coin c2;
	int cnt;
}qData;

int N, M;
int min_cnt = INF;
char board[20][20];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
bool visited[20][20][20][20];

bool isOut(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M)
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	bool flag = true;
	coin c1, c2;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];

			if (board[i][j] == 'o') {
				if (flag) {
					c1.x = i;
					c1.y = j;
					flag = false;
				}
				else {
					c2.x = i;
					c2.y = j;
				}
			}
		}
	}

	queue<qData> q;
	q.push({c1, c2, 0});
	visited[c1.x][c1.y][c2.x][c2.y] = true;

	while (!q.empty()) {
		qData data = q.front();
		int cnt = data.cnt;
		c1 = data.c1;
		c2 = data.c2;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int x1 = c1.x + dx[d];
			int y1 = c1.y + dy[d];

			int x2 = c2.x + dx[d];
			int y2 = c2.y + dy[d];

			bool isOut1 = isOut(x1, y1);
			bool isOut2 = isOut(x2, y2);

			// 동전 둘 다 떨어질 때
			if (isOut1 && isOut2)
				continue;
			// 둘 중 하나만 떨어졌을 때
			else if ((!isOut1 && isOut2) || (isOut1 && !isOut2)) {
				int _cnt = cnt + 1;
				min_cnt = _cnt < min_cnt ? _cnt : min_cnt;
			}		
			// 둘 다 안 떨어졌을 때
			else if (board[x1][y1] != '#' || board[x2][y2] != '#') {
				if (board[x1][y1] == '#') {
					x1 = c1.x;
					y1 = c1.y;
				}

				if (board[x2][y2] == '#') {
					x2 = c2.x;
					y2 = c2.y;
				}

				if (!visited[x1][y1][x2][y2] && cnt + 1 <= 10) {
					visited[x1][y1][x2][y2];

					coin _c1 = { x1, y1 };
					coin _c2 = { x2, y2 };

					q.push({ _c1, _c2, cnt + 1 });
				}
			}
		}
	}

	if (min_cnt == INF) {
		min_cnt = -1;
	}

	cout << min_cnt;

	return 0;
}