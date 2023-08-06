#include <iostream>
#include <queue>
#define MAX 501
using namespace std;

int N, M, A, B, K;
int sy, sx, ey, ex;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int answer = 0;

bool isAvailable(int y, int x) {
  for (int i = y; i < y+A; i++) {
    for (int j = x; j < x+B; j++) {
      if(map[i][j] == -1) return false;
    }
  }
  return true;
}

int bfs() {
  queue<pair<int, int>> q;

  q.push({sy, sx});
  visited[sy][sx] = true;

  while(!q.empty()) {
    int size = q.size();

    for (int s = 0; s < size; s++) {
      int y = q.front().first;
      int x = q.front().second;
      q.pop();

      if(y == ey && x == ex) return answer;

      for (int d = 0; d < 4; d++) {
        int ny = y + dy[d];
        int nx = x + dx[d];

        if(ny <= 0 || ny+A-1> N || nx<=0 || nx+B-1>M || !isAvailable(ny, nx) || visited[ny][nx]) continue;

        q.push({ny, nx});
        visited[ny][nx] = true;
      }
    }

    answer++;
  }

  return -1;
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M >> A >> B >> K;
  for (int i = 0; i < K; i++) {
    int r, c;
    cin >> r >> c;
    map[r][c] = -1;
  }
  cin >> sy >> sx >> ey >> ex;

  cout << bfs() << "\n";
  return 0;
}