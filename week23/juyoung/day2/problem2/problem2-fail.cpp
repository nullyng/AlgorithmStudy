#include <iostream>
#include <string>
#include <cstring>
#include <map>
using namespace std;

int N, M, K;
string board[11];
string str[1001];
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
map<string, int> m;
int cnt = 0;

pair<int, int> change_range(int y, int x) {
  if(y == -1) y = N - 1;
  else if(y == N) y = 0;

  if(x == -1) x = M - 1;
  else if(x == M) x = 0;

  return {y, x};
}

void dfs(int y, int x, string s, int index) {
  for (int i = 0; i < 8; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if(ny<0 || ny >=N || nx<0 || nx>=M) {
      pair<int, int> result = change_range(ny, nx);
      ny = result.first;
      nx = result.second;
    }
    if (board[ny][nx] == s[index]) {
      if(index == s.length()-1) {
        cnt++;
        continue;
      }
      dfs(ny, nx, s, index + 1);
    }
  }
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M >> K;
  for (int i = 0; i < N; i++) cin >> board[i];
  for (int i = 0; i < K; i++) cin >> str[i];

  // 모든 문자열에 대해 검사한다.
  for (int i = 0; i < K; i++) {
    // 이미 해당 문자열에 대해 탐색한 기록이 있으면 이를 출력한다.
    if(m[str[i]]) cout << m[str[i]];
    else {
      cnt = 0;

      // 어디서든 시작할 수 있으므로 격자의 모든 곳에서 시작
      for(int j=0; j<N; j++) {
        for(int k=0; k<M; k++) {
          // 방문 순서가 다르면 다른 경우이므로 방문 여부는 체크하지 않는다.
          // 시작 위치가 현재 문자열의 첫 문자와 같은 경우에만 탐색한다.
          if(board[j][k] == str[i][0]) {
            dfs(j, k, str[i], 1);
          }
        }
      }

      m[str[i]] = cnt;
      cout << cnt << "\n";
    }
  }


  return 0;
}