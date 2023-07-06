#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int paper[501][501];
bool visited[501][501];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int cnt, max_size;

int bfs(int sy, int sx) {
  queue<pair<int, int>> q;
  int s = 1;

  q.push({sy, sx});
  visited[sy][sx] = true;

  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
      if(visited[ny][nx] || !paper[ny][nx]) continue;

      visited[ny][nx] = true;
      q.push({ny, nx});
      s++;
    }
  }

  return s;
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> paper[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if(!visited[i][j] && paper[i][j]) {
        max_size = max(max_size, bfs(i, j));
        cnt++;
      }
    }
  }

  cout << cnt << "\n" << max_size << "\n";
  return 0;
}