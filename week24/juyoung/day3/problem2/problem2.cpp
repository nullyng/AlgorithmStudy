#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N;
string grid[101];
bool visited[101][101];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int ans1, ans2;

void bfs(int sy, int sx) {
  queue<pair<int, int>> q;
  
  q.push({sy, sx});
  visited[sy][sx] = true;
  
  while(!q.empty()) {
      int y = q.front().first;
      int x = q.front().second;
      q.pop();
      
      for(int i=0; i<4; i++) {
          int ny = y + dy[i];
          int nx = x + dx[i];
          
          if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
          if(visited[ny][nx]) continue;
          if(grid[sy][sx] != grid[ny][nx]) continue;
          
          q.push({ny, nx});
          visited[ny][nx] = true;
      }
  }
}
  
int main() {
cin.tie(NULL); cout.tie(NULL);
ios_base::sync_with_stdio(false);
  
cin >> N;
  for(int i=0; i<N; i++) cin >> grid[i];
  
  // 적록색약이 아닌 사람에 대해 BFS
  for(int i=0; i<N; i++) {
      for(int j=0; j<N; j++) {
          if(visited[i][j]) continue;
          bfs(i, j);
          ans1++;
      }
  }
  
  // 그리드에서 R을 G로 바꾸고 visited 초기화
  for(int i=0; i<N; i++) {
      for(int j=0; j<N; j++) {
          visited[i][j] = false;
          if(grid[i][j] == 'R')
              grid[i][j] = 'G';
      }
  }
  
  // 적록색약인 사람에 대해 BFS
  for(int i=0; i<N; i++) {
      for(int j=0; j<N; j++) {
          if(visited[i][j]) continue;
          bfs(i, j);
          ans2++;
      }
  }
  
  cout << ans1 << " " << ans2 << "\n";
  return 0;
}
