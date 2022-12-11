#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

typedef struct pos {
	int x, y;
}pos;

int N, M;
int max_area = 0;
int map[8][8];
int dx[] = { -1, 0 ,1, 0 };
int dy[] = { 0, 1, 0, -1 };
bool visited[8][8];
vector<pos> v;

int virus() {
	queue<pos> q;
	bool spread[8][8];
	
	memset(spread, false, sizeof(bool) * 64);

	for (int i = 0; i < (int)v.size(); i++) {
		q.push(v[i]);
		spread[v[i].x][v[i].y] = true;
	}

	while (!q.empty()) {
		int cnt = (int)q.size();

		for (int i = 0; i < cnt; i++) {
			pos p = q.front();
			q.pop();

			for (int d = 0; d < 4; d++) {
				int _x = p.x + dx[d];
				int _y = p.y + dy[d];

				if (_x < 0 || _x >= N || _y < 0 || _y >= M)
					continue;

				if (!map[_x][_y] && !spread[_x][_y]) {
					spread[_x][_y] = true;
					q.push({ _x, _y });
				}
			}
		}
	}

	int area = 0;

	for(int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (!map[i][j] && !spread[i][j])
				area++;

	return area;
}

void comb(int x, int y, int cnt) {
	if (cnt == 3) {
		int area = virus();
		max_area = area > max_area ? area : max_area;
		return;
	}

	int _x = x;
	int _y = y;

	while (1) {
		if (map[_x][_y] == 0) {
			map[_x][_y] = 1;
			comb(_x, _y, cnt + 1);
			map[_x][_y] = 0;
		}

		_y++;

		if (_y >= M) {
			_y = 0;
			if (++_x >= N)
				break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	queue<pos> q;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];

			if (map[i][j] == 2) {
				v.push_back({ i, j });
			}
		}
	}

	comb(0, 0, 0);

	cout << max_area;

	return 0;
}