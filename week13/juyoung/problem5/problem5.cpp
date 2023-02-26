#include <iostream>
#include <cstring>
using namespace std;

int M, N;
int map[501][501];
int dp[501][501];
bool visited[501][501];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int dfs(int y, int x) {
  if(y == M && x == N) return 1;
  if(visited[y][x]) return dp[y][x];

  visited[y][x] = true;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if(ny<=0 || ny>M || nx<=0 || nx>N) continue;
    if(map[ny][nx] >= map[y][x]) continue;

    dp[y][x] += dfs(ny, nx);
  }

  return dp[y][x];
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> M >> N;

  for (int i = 1; i <= M; i++) {
    for (int j = 1; j <= N; j++)
      cin >> map[i][j];
  }

  cout << dfs(1, 1) << "\n";

  return 0;
}