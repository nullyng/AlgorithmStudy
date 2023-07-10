#include <iostream>
#include <string>
#include <queue>

using namespace std;

typedef struct info {
  int x;
  int y;
  string s;
}info;

const int MAX = 20;

char board[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool findChar(string s, char target) {
  for(char c : s) {
    if(c == target) return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int R, C;

  cin >> R >> C;

  for(int i = 0; i < R; i++)
    for(int j = 0; j < C; j++)
      cin >> board[i][j];
    
  queue<info> q;
  int maxCells = 0;
  string s = "";
  s += board[0][0];

  q.push({0, 0, s});
  visited[0][0] = true;

  while(!q.empty()) {
    info mal = q.front();
    q.pop();

    if((int)mal.s.length() > maxCells)
      maxCells = (int)mal.s.length();

    for(int d = 0; d < 4; d++) {
      int rx = mal.x + dx[d];
      int ry = mal.y + dy[d];

      if(rx < 0 || rx >= R || ry < 0 || ry >= C) continue;
      if(visited[rx][ry] || findChar(mal.s, board[rx][ry])) continue;

      string new_s(mal.s);
      new_s += board[rx][ry];
      visited[rx][ry] = true;
      q.push({rx, ry, new_s});
    }  
  }

  cout << maxCells;

  return 0;
}