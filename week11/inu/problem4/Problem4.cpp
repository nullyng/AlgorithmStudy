#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

char map[5][5];
int answer = 0;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
bool selected[5][5];

typedef struct pos {
	int x, y;
}pos;

void BFS() {
	queue<pos> q;
	bool visited[5][5];
	int cnt = 0;

	memset(visited, false, sizeof(visited));

	for (int i = 0; i < 5; i++) {
		bool flag = false;

		for (int j = 0; j < 5; j++)
			if (selected[i][j]) {
				visited[i][j] = true;
				q.push({ i, j });
				cnt++;
				flag = true;
				break;
			}

		if (flag) break;
	}	
	
	while (!q.empty()) {
		pos p = q.front();
		q.pop();

		if (cnt == 7) {
			answer++;
			break;
		}

		for (int d = 0; d < 4; d++) {
			int rx = p.x + dx[d];
			int ry = p.y + dy[d];

			if (rx < 0 || rx >= 5 || ry < 0 || ry >= 5)
				continue;

			if (visited[rx][ry] || !selected[rx][ry])
				continue;

			q.push({ rx, ry });
			visited[rx][ry] = true;
			cnt++;
		}
	}

	return;
}

void comb(int cur, int cnt, int som) {
	if (cnt == 7) {
		if (som >= 4)
			BFS();

		return;
	}

	for (int n = cur; n < 25; n++) {
		int i = n / 5;
		int j = n % 5;

		if (selected[i][j]) continue;

		selected[i][j] = true;
		int _som = map[i][j] == 'S' ? som + 1 : som;
		comb(n + 1, cnt + 1, _som);
		selected[i][j] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> map[i][j];
	
	comb(0, 0, 0);

	cout << answer;

	return 0;
}