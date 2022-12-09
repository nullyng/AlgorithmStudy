#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
int map[8][8];
vector<pair<int, int>> zero;
vector<pair<int, int>> virus;
pair<int, int> comb[3];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int answer = -1;

int bfs(pair<int, int> comb[]) {
  int copy[8][8];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      copy[i][j] = map[i][j];
    }
  }

  for (int i = 0; i < 3; i++) {
    int y = comb[i].first;
    int x = comb[i].second;
    copy[y][x] = 1;
  }

  queue<pair<int, int>> q;
  bool visited[8][8];

  for (int i = 0; i < virus.size(); i++)
    q.push(virus[i]);

  memset(visited, false, sizeof(visited));
  
  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    visited[y][x] = true;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
      if(visited[ny][nx] || copy[ny][nx] == 1) continue;
      q.push({ny, nx});
      copy[ny][nx] = 2;
      visited[ny][nx] = true;
    }
  }

  int safe = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if(copy[i][j] == 0) safe++;
    }
  }

  return safe;
}

void makeComb(int cnt, int idx) {
  if(cnt == 3) {
    int safe = bfs(comb);
    answer = max(answer, safe);
    return;
  }

  for (int i = idx; i < zero.size(); i++) {
    comb[cnt] = zero[i];
    makeComb(cnt + 1, i + 1);
  }
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> map[i][j];
      if(map[i][j] == 0) zero.push_back({i, j});
      else if(map[i][j] == 2) virus.push_back({i, j});
    }
  }

  makeComb(0, 0);

  cout << answer << "\n";
  return 0;
}