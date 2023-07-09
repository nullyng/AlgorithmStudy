#include <iostream>
#include <string>
using namespace std;

int R, C;
string board[21];
int alphabet[26];
int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};
int answer;

void dfs(int y, int x, int depth) {
  answer = max(answer, depth);

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    int alpha_index = board[ny][nx] - 'A';

    if(ny<0 || ny>=R || nx<0 || nx>=C) continue;
    if(alphabet[board[ny][nx]-'A']) continue;

    alphabet[board[ny][nx]-'A'] = true;
    dfs(ny, nx, depth + 1);
    alphabet[board[ny][nx]-'A'] = false;
  }
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> R >> C;
  for (int i = 0; i < R; i++) cin >> board[i];

  alphabet[board[0][0]-'A'] = true;
  dfs(0, 0, 1);

  cout << answer << "\n";
  return 0;
}