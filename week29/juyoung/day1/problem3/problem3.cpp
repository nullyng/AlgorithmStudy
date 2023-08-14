#include <iostream>
#include <cstring>
#include <vector>
#define MAX 2001
using namespace std;

int N, M;
int lab[MAX][MAX];
bool visited[MAX][MAX][4];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};
vector<pair<int, int>> aircon;
int cnt = 0;

int changeDirection(int obj, int d) {
  switch(obj) { 
    case 1: if(d==1 || d==3) d = -1;
      break;
    case 2: if(d==0 || d==2) d = -1;
      break;
    case 3: if(d==0) d = 3;
        else if(d==1) d = 2;
        else if(d==2) d = 1;
        else d = 0;
        break;
    case 4: if(d==0) d = 1;
        else if(d==1) d = 0;
        else if(d==2) d = 3;
        else d = 2;
        break;
  }

  return d;
}

void dfs(int y, int x, int d) {
  visited[y][x][d] = true;
  d = changeDirection(lab[y][x], d);
  if(d == -1) return;

  int ny = y + dy[d];
  int nx = x + dx[d];
  if(ny<0 || ny>=N || nx<0 || nx>=M || visited[ny][nx][d]) return;

  dfs(ny, nx, d);
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> lab[i][j];
      if(lab[i][j] == 9) {
        aircon.push_back({i, j});
      }
    }
  }
  
  for (int i = 0; i < aircon.size(); i++) {
    for (int j = 0; j < 4; j++) {
      dfs(aircon[i].first, aircon[i].second, j);
    }
  }

  int answer = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      bool flag = false;
      for (int k = 0; k < 4; k++) {
        if(visited[i][j][k]) {
          flag = true;
          break;
        }
      }
      if(flag) answer++;
    }
  }

  cout << answer << "\n";
  return 0;
}