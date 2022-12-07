#include <iostream>
#include <vector>
#include <algorithm>
#define INF 99999
using namespace std;

int N, M;
char board[20][20];
vector<pair<int, int>> coin;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int answer = INF;

void dfs(int move, int y1, int x1, int y2, int x2) {
  if(answer <= move) return;
  if(move > 10) return;

  // 동전 중 떨어진 것이 있는지 확인한다.
  int cnt = 0;
  if (y1 < 0 || y1 >= N || x1 < 0 || x1 >= M) cnt++;
  if (y2 < 0 || y2 >= N || x2 < 0 || x2 >= M) cnt++;
  
  if(cnt > 0) {
    if(cnt == 2) return;
    answer = min(answer, move);
    return;
  }

  // 네 방향 중 이동할 수 있는 곳으로 동전을 이동시킨다.
  for (int i = 0; i < 4; i++) {
    int ny1 = y1 + dy[i];
    int nx1 = x1 + dx[i];
    int ny2 = y2 + dy[i];
    int nx2 = x2 + dx[i];
      
    if (board[ny1][nx1] == '#' && board[ny2][nx2] == '#') continue;
    else if(board[ny1][nx1] == '#') dfs(move + 1, y1, x1, ny2, nx2);
    else if(board[ny2][nx2] == '#') dfs(move + 1, ny1, nx1, y2, x2);
    else dfs(move + 1, ny1, nx1, ny2, nx2);
  }
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
      if(board[i][j] == 'o')
        coin.push_back({i, j});
    }
  }

  dfs(0, coin[0].first, coin[0].second, coin[1].first, coin[1].second);

  if(answer == INF) cout << "-1\n";
  else cout << answer << "\n";
  
  return 0;
}