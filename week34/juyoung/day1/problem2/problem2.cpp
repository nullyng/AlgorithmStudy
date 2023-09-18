#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
int space[51][51];
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int answer;

int bfs(int y, int x) {
  queue<pair<int, int>> q;
  bool visited[51][51];
  int safeDistance = 0;

  memset(visited, false, sizeof(visited));
  q.push({y, x});
  visited[y][x] = false;

  while(!q.empty()) {
    int size = q.size();
    safeDistance++;

    for (int i = 0; i < size; i++) {
      y = q.front().first;
      x = q.front().second;
      q.pop();

      for (int i = 0; i < 8; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny<0 || ny>=N || nx<0 || nx>=M || visited[ny][nx]) continue;
        if(space[ny][nx] == 1) return safeDistance;

        q.push({ny, nx});
        visited[ny][nx] = true;
      }
    }  
  }

  return 0;
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> space[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if(space[i][j] == 1) continue;
      answer = max(bfs(i, j), answer);
    }
  }

  cout << answer << "\n";
  return 0;
}