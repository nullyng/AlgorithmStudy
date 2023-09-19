#include <iostream>
#define MAX 19
using namespace std;

int baduk[MAX][MAX];
int dy[2][4] = {{0, 1, 1, 1}, {0, -1, -1, -1}};
int dx[2][4] = {{1, 1, 0, -1}, {-1, -1, 0, 1}};
int answerColor, answerY = 99, answerX = 99;

bool checkRange(int y, int x) {
  if(y<0 || y>=MAX || x<0 || x>=MAX) return false;
  return true;
}

int dfs(int y, int x, int dirIdx, int d, int cnt) {
  // 바둑알이 5개가 넘으면 더 이상 탐색하지 않는다.
  if(cnt > 5) return 99;

  int ny = y + dy[dirIdx][d];
  int nx = x + dx[dirIdx][d];
  if(!checkRange(ny, nx)) return cnt;
  if(baduk[ny][nx] == baduk[y][x]) cnt = dfs(ny, nx, dirIdx, d, cnt+1);

  return cnt;
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      cin >> baduk[i][j];
    }
  }

  for (int y = 0; y < MAX; y++) {
    for (int x = 0; x < MAX; x++) {
      if(baduk[y][x] == 0) continue;

      for (int d = 0; d < 4; d++) {
        int omokCnt = 1;
        int ny1 = y + dy[0][d];
        int nx1 = x + dx[0][d];
        int ny2 = y + dy[1][d];
        int nx2 = x + dx[1][d];

        // 범위 체크를 한다.
        if(checkRange(ny1, nx1)) {
          // 현재 위치와 다음 위치의 바둑알이 같은 색이라면
          // 현재 방향으로 쭉 탐색하며 같은 색 바둑알이 연속된 개수를 세아린다.
          if(baduk[y][x] == baduk[ny1][nx1]) omokCnt += dfs(ny1, nx1, 0, d, 1);
        }
        if(checkRange(ny2, nx2)) {
          // 반대 방향에 대해서도 같은 색 바둑알이 연속된 개수를 세아리다.
          if(baduk[y][x] == baduk[ny2][nx2]) omokCnt += dfs(ny2, nx2, 1, d, 1);
        }
       
        if(omokCnt == 5) {
          if(x < answerX) {
            answerColor = baduk[y][x];
            answerY = y;
            answerX = x;
          }
          break;
        }
      }
    }
  }

  if(answerColor) {
    cout << answerColor << "\n";
    cout << answerY+1 << " " << answerX+1 << "\n";
  } else cout << "0\n";

  return 0;
}