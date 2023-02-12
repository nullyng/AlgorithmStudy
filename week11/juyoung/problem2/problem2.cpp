#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 999999
using namespace std;

int N, M;
int lab[50][50];
int emptyCnt = 0;
vector<pair<int, int>> virus;
pair<int, int> selected[11];
int visited[50][50];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int answer = INF;

void bfs() {
  queue<pair<int, int>> q;
  int time = 0;
  int cnt = 0;

  for (int i = 0; i < M; i++) {
    int y = selected[i].first;
    int x = selected[i].second;
    q.push({y, x});
    visited[y][x] = 0;
  }

  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
      if (visited[ny][nx] >= 0 || lab[ny][nx] == 1) continue;
      visited[ny][nx] = visited[y][x] + 1;
      q.push({ny, nx});
      if (lab[ny][nx] == 0) {
        cnt++;
        time = visited[ny][nx];
      }
    }
  }

  if(cnt == emptyCnt) answer = min(answer, time);
}

void makeComb(int cnt, int idx) {
  if(cnt == M) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        visited[i][j] = -1;
      }
    }

    bfs();

    return;
  }

  for (int i = idx; i < (int)virus.size(); i++) {
    selected[cnt] = virus[i];
    makeComb(cnt + 1, i + 1);
  }
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> lab[i][j];
      if (lab[i][j] == 0) emptyCnt++;
      else if (lab[i][j] == 2) virus.push_back({i, j});
    }
  }

  makeComb(0, 0);
  if (answer == INF) answer = -1;
  cout << answer << "\n";

  return 0;
}