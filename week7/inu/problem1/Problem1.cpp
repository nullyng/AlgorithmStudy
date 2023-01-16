#include <iostream>
#include <queue>
#define INF 99999

using namespace std;

typedef struct pos {
	int x, y;
	int w;
}pos;

char miro[100][100];
int dist[100][100];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> miro[i][j];
			dist[i][j] = INF;
		}
	}
		
	queue<pos> q;
	dist[0][0] = 0;
	q.push({ 0, 0, 0 });
	
	while (!q.empty()) {
		pos p = q.front();
		q.pop();

		for (int d = 0; d < 4; d++) {
			int rx = p.x + dx[d];
			int ry = p.y + dy[d];

			if (rx < 0 || rx >= M || ry < 0 || ry >= N)
				continue;

			if (dist[p.x][p.y] + (miro[rx][ry] - '0') < dist[rx][ry]) {
				dist[rx][ry] = dist[p.x][p.y] + (miro[rx][ry] - '0');
				q.push({ rx, ry, dist[rx][ry] });
			}
		}
	}

	cout << dist[M - 1][N - 1];

	return 0;
}