#include <iostream>
#include <queue>

using namespace std;

const int MAX = 500;

typedef pair<int, int> pii;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int answer = 250000;
int N, M, A, B, K;
int s_r, s_c, e_r, e_c;
bool map[MAX][MAX];
bool isVisited[MAX][MAX];

bool isMovable(int x, int y) {
	// 범위 밖인지 체크
	if (x < 0 || x + A - 1 >= N || y < 0 || y + B - 1 >= M)
		return false;

	// 장애물이 있는지 체크
	for (int rx = x; rx < x + A; rx++)
		for (int ry = y; ry < y + B; ry++)
			if (map[rx][ry]) return false;

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> A >> B >> K;

	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		map[a - 1][b - 1] = true;
	}

	cin >> s_r >> s_c >> e_r >> e_c;

	queue<pair<pii, int>> q;
	q.push({ { s_r - 1, s_c - 1 }, 0 });
	isVisited[s_r - 1][s_c - 1] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int move = q.front().second;
		q.pop();

		if (x == e_r - 1 && y == e_c - 1) {
			answer = move;
			break;
		}

		for (int d = 0; d < 4; d++) {
			int rx = x + dx[d];
			int ry = y + dy[d];

			if (!isVisited[rx][ry] && isMovable(rx, ry)) {
				isVisited[rx][ry] = true;
				q.push({ {rx, ry}, move + 1 });
			}
		}
	}

	if (answer == 250000) answer = -1;

	cout << answer;

	return 0;
}