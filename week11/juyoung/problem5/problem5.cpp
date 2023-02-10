#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define INF 999999
using namespace std;

int N;
int map[101][101];
vector<pair<int, int>> area;
bool visited[101][101];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int continent;
int answer = INF;

void numbering(int y, int x) {
  queue<pair<int, int>> q;

  q.push({y, x});
  visited[y][x] = true;
  map[y][x] = continent;

  while(!q.empty()) {
    y = q.front().first;
    x = q.front().second;
    q.pop();

    for(int i=0; i<4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      
      if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
      if(visited[ny][nx] || !map[ny][nx]) continue;
      
      map[ny][nx] = continent;
      visited[ny][nx] = true;
      q.push({ny, nx});
    }
  }
}

int bfs(int c) {
  queue<pair<int, int>> q;
  int dist = 0;

  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      if(map[i][j] == c) {
        q.push({i, j});
        visited[i][j] = true;
      }
    }
  }

  while(!q.empty()) {
    int size = q.size();
    
    for(int i=0; i<size; i++) {
      int y = q.front().first;
      int x = q.front().second;
      q.pop();

      for(int j=0; j<4; j++) {
        int ny = y + dy[j];
        int nx = x + dx[j];

        if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
        if(visited[ny][nx]) continue;
        if(map[ny][nx] && map[y][x] != c) return dist;
        if(map[ny][nx] == 0) {
          q.push({ny, nx});
          visited[ny][nx] = true;
        }
      }
    }

    dist++;
  }
    
  return INF;
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      cin >> map[i][j];
      if(map[i][j]) map[i][j] = -1;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if(map[i][j] == -1) {
        continent++;
        numbering(i, j);
      }
    }
  }

  for (int i = 1; i <= continent; i++) {
    memset(visited, false, sizeof(visited));
    answer = min(answer, bfs(i));
  }

  cout << answer << "\n";
  return 0;
}