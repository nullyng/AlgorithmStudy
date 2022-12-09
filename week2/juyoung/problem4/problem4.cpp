#include <iostream>
#include <queue>
using namespace std;

int R, C;
char map[50][50];
queue<pair<int, int>> q;
queue<pair<int, int>> water;
bool visited[50][50];
bool w_visited[50][50];
int dir_y[4] = {-1, 1, 0, 0};
int dir_x[4] = {0, 0, -1, 1};

bool check_range(int y, int x) {
  if(y < 0 || y >= R || x < 0 || x >= C)
    return false;
  return true;
}

void bfs_water() {
  int size = water.size();

  for (int s = 0; s < size; s++) {
    int y = water.front().first;
    int x = water.front().second;
    water.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dir_y[i];
      int nx = x + dir_x[i];

      if(!check_range(ny, nx)) continue;
      if(w_visited[ny][nx] || map[ny][nx] == 'D' || map[ny][nx] == 'X') continue;
      water.push({ny, nx});
      w_visited[ny][nx] = true;
      map[ny][nx] = '*';
    }
  }
}

int bfs() {
  int time = 0;

  while (!q.empty()) {
    bfs_water();
    time++;
    
    int size = q.size();
    for (int i = 0; i < size; i++) {
      int y = q.front().first;
      int x = q.front().second;
      q.pop();

      for (int i = 0; i < 4; i++) {
        int ny = y + dir_y[i];
        int nx = x + dir_x[i];

        if (!check_range(ny, nx)) continue;
        if (visited[ny][nx] || map[ny][nx] == '*' || map[ny][nx] == 'X') continue;
        if (map[ny][nx] == 'D') return time;

        q.push({ny, nx});
        visited[ny][nx] = true;
      }
    }
  }

  return -1;
}

int main() {
  cin >> R >> C;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> map[i][j];

      if(map[i][j] == 'S')
        q.push({i, j});
      else if (map[i][j] == '*')
        water.push({i, j});
    }
  }

  int answer = bfs();

  if(answer > 0) cout << answer << "\n";
  else cout << "KAKTUS\n";
}