#include <iostream>
#include <string>
#include <map>
using namespace std;

int N, M, K;
string board[11];
string str[1001];
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
map<string, int> m;
string s;

pair<int, int> change_range(int y, int x) {
  if(y == -1) y = N - 1;
  else if(y == N) y = 0;

  if(x == -1) x = M - 1;
  else if(x == M) x = 0;

  return {y, x};
}

void dfs(int y, int x) {
  if(s.length() > 5) return;

  auto iter = m.find(s);
  if(iter != m.end()) iter->second++;

  for (int i = 0; i < 8; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if(ny<0 || ny>=N || nx<0 || nx>=M) {
      pair<int, int> result = change_range(ny, nx);
      ny = result.first;
      nx = result.second;
    }

    s += board[ny][nx];
    dfs(ny, nx);
    s.pop_back();
  }
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M >> K;
  for (int i = 0; i < N; i++) cin >> board[i];
  for (int i = 0; i < K; i++) {
    cin >> str[i];
    m.insert({str[i], 0});
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      s.push_back(board[i][j]);
      dfs(i, j);
      s.clear();
    }
  }

  for (int i = 0; i < K; i++) cout << m[str[i]] << "\n";
  return 0;
}