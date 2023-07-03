#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int N;
int home[17][17];
int dy[3] = {0, 1, 1}; // 오른쪽, 대각선, 아래
int dx[3] = {1, 1, 0};
int answer;

void bfs() {
  queue<tuple<int, int, int>> q; // y, x, 파이프 방향(0, 1, 2)

  q.push({1, 2, 0});

  while(!q.empty()) {
    int y = get<0>(q.front());
    int x = get<1>(q.front());
    int dir = get<2>(q.front());
    q.pop();

    for (int i = 0; i < 3; i++) {
      // 파이프 방향이 가로인데 아래로 이동하려고 하면 continue
      if(dir == 0 && i == 2) continue;
      // 파이프 방향이 세로인데 오른쪽으로 이동하려고 하면 continue
      if(dir == 2 && i == 0) continue;

      int ny = y + dy[i];
      int nx = x + dx[i];

      if(ny <= 0 || ny > N || nx<=0 || nx > N) continue;
      if(home[ny][nx] == 1) continue;
      // 대각선으로 이동하려고 할 때 위, 왼쪽 칸이 비어있는지 확인
      if(i == 1 && (home[ny-1][nx] || home[ny][nx-1])) continue;

      // (N, N)에 도착했다면 정답 카운트, 아니라면 queue에 push
      if(ny == N && nx == N) answer++;
      else q.push({ny, nx, i});
    }
  }
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> home[i][j];
    }
  }

  bfs();

  cout << answer << "\n";
  return 0;
}