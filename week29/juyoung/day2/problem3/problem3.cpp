#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int board[101][101];
bool visited[101][101];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int totalTime, cheese, answer;

int bfs() {
  queue<pair<int, int>> q;
  int melt = 0;

  q.push({0, 0});
  visited[0][0] = true;

  while(!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if(ny<0 || ny>=N || nx<0 || nx>=M || visited[ny][nx]) continue;
      if(board[ny][nx] == 1) {
        // 치즈라면 공기로 바꾸고 개수를 더한다.
        board[ny][nx] = 0;
        melt++;
      } else {
        q.push({ny, nx});
      }
      visited[ny][nx] = true;
    }
  }

  return melt;
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
    }
  }

  while(1) {
    memset(visited, false, sizeof(visited));
    cheese = bfs();
    if(cheese <= 0) break;
    totalTime++;
    answer = cheese;
  }

  cout << totalTime << "\n"
       << answer << "\n";
  
  return 0;
}