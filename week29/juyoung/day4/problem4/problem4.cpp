#include <iostream>
#include <string>
#define MAX 501
using namespace std;

int N, M;
string maze[MAX];
bool visited[MAX][MAX];
bool escape[MAX][MAX];
int answer;

bool dfs(int y, int x) {
  if(escape[y][x]) return true;

  int ny = y, nx = x;

  if(maze[y][x] == 'U') ny--;
  else if(maze[y][x] == 'D') ny++;
  else if(maze[y][x] == 'L') nx--;
  else nx++;

  if(ny<0 || ny>=N || nx<0 || nx>=M) {
    return escape[y][x] = true;
  }
  if(visited[ny][nx]) return escape[y][x] = escape[ny][nx];
  visited[ny][nx] = true;

  return escape[y][x] = dfs(ny, nx);
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> maze[i];

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if(escape[i][j] || visited[i][j]) continue;
      visited[i][j] = true;
      escape[i][j] = dfs(i, j);
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if(escape[i][j]) answer++;
    }
  }

  cout << answer << "\n";
  return 0;
}