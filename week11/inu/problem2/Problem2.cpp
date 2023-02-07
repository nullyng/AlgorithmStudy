#include <iostream>
#include <vector>
#include <queue>
#define MAX 100000

using namespace std;

typedef struct pos {
	int x, y;
}pos;

int N, M;
int blank = 0;
int min_time = MAX;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int map[50][50];
vector<pos> virus;

int BFS(vector<pos> selected) {
	int time = 0;
	int remain = blank;
	bool visited[50][50] = { false, };
	queue<pair<int, pos>> q;

	for (pos p : selected) {
		q.push({ 0, p });
		visited[p.x][p.y] = true;
	}
		
	while (!q.empty()) {
		int q_size = (int)q.size();

		for (int i = 0; i < q_size; i++) {
			int t = q.front().first;
			pos p = q.front().second;
			q.pop();

			if (time != t) time = t;

			for (int d = 0; d < 4; d++) {
				int x = p.x + dx[d];
				int y = p.y + dy[d];

				if (x < 0 || x >= N || y < 0 || y >= N)
					continue;

				if (map[x][y] != 1 && !visited[x][y]) {
					visited[x][y] = true;
					q.push({ t + 1, { x, y } });
					
					if (!map[x][y] && !(--remain)) {
						return t + 1;
					}
				}
			}
		}
	}

	if (remain != 0) time = -1;

	return time;
}

void comb(int cnt, int idx, vector<pos> selected) {
	if (idx >= (int)virus.size() || cnt == M) {
		if (cnt == M) {
			int time = BFS(selected);
			min_time = time == -1 ? min_time : min(min_time, time);
		}

		return;
	}

	for (int i = idx; i < (int)virus.size(); i++) {
		selected.push_back(virus[i]);
		comb(cnt + 1, i + 1, selected);
		selected.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for(int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];

			switch (map[i][j]) {
			case 0:
				blank++;
				break;
			case 2:
				virus.push_back({ i, j });
			}
		}

	if (blank == 0)
		min_time = 0;
	else
		comb(0, 0, vector<pos>());

	if (min_time == MAX) min_time = -1;

	cout << min_time;

	return 0;
}