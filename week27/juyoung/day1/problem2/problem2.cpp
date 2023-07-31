#include <iostream>
#include <queue>
using namespace std;

int M, N;
int paper[251][251];
bool visited[251][251];
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int answer;

void bfs(int sy, int sx) {
  queue<pair<int, int>> q;

  q.push({sy, sx});
  visited[sy][sx] = true;

  while(!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int i = 0; i < 8; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if(ny<0 || ny>=M || nx<0 || nx>=N) continue;
      if(visited[ny][nx] || !paper[ny][nx]) continue;

      q.push({ny, nx});
      visited[ny][nx] = true;
    }
  }
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> M >> N;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> paper[i][j];
    }
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if(visited[i][j] || !paper[i][j]) continue;
      bfs(i, j);
      answer++;
    } 
  }

  cout << answer << "\n";
  return 0;
}