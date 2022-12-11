#include <iostream>
#include <queue>
#define INF 99999

using namespace std;

typedef struct pos {
	int x, y;
}pos;

typedef struct qData {
	pos p;
	int time;
}qData;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
bool water_check[50][50];
bool hog_check[50][50];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int R, C;
	int min_time = INF;
	char map[50][50];
	pos S, D;
	queue<pos> water_q;
	queue<qData> hog_q;

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];

			switch (map[i][j]) {
			case 'S':
				S.x = i;
				S.y = j;
				hog_check[i][j] = true;
				hog_q.push({ {i, j}, 0 });
				break;
			case 'D':
				D.x = i;
				D.y = j;
				break;
			case '*':
				water_check[i][j] = true;
				water_q.push({ i, j });
			}
		}
	}


	while (!hog_q.empty()) {
		// 물 이동
		int cnt = (int)water_q.size();

		for (int i = 0; i < cnt; i++) {
			pos p = water_q.front();
			water_q.pop();

			for (int d = 0; d < 4; d++) {
				int _x = p.x + dx[d];
				int _y = p.y + dy[d];

				if (_x < 0 || _x >= R || _y < 0 || _y >= C)
					continue;

				if (map[_x][_y] != 'X' && map[_x][_y] != 'D' && !water_check[_x][_y]) {
					map[_x][_y] = '*';
					water_check[_x][_y] = true;
					water_q.push({ _x, _y });
				}
			}
		}

		// 고슴도치 이동
		cnt = (int)hog_q.size();

		for (int i = 0; i < cnt; i++) {
			qData data = hog_q.front();
			pos p = data.p;
			int time = data.time;
			hog_q.pop();

			for (int d = 0; d < 4; d++) {
				int _x = p.x + dx[d];
				int _y = p.y + dy[d];

				if (_x < 0 || _x >= R || _y < 0 || _y >= C)
					continue;

				switch (map[_x][_y]) {
				case 'D':
					min_time = time + 1 < min_time ? time + 1 : min_time;
					break;
				case '.':
					if (!hog_check[_x][_y]) {
						hog_check[_x][_y] = true;
						hog_q.push({ {_x, _y}, time + 1 });
					}
					break;
				}
			}
		}
	}

	if (min_time == INF) {
		cout << "KAKTUS";
	}
	else {
		cout << min_time;
	}

	return 0;
}