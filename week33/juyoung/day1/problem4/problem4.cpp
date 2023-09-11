#include <iostream>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

int N, M, K;
int map[1001][1001];
int visited[1001][1001][11];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

void bfs() {
  queue<tuple<int, int, int, int>> q; // y, x, 경로 길이, 부순 벽의 개수

  // 시작과 끝을 경로에 포함한다고 했으므로 경로 길이는 1에서 시작한다.
  q.push({0, 0, 1, 0});
  visited[0][0][0] = true;

  while(!q.empty()) {
    int y = get<0>(q.front());
    int x = get<1>(q.front());
    int d = get<2>(q.front());
    int w = get<3>(q.front());
    q.pop();

    if(y == N-1 && x == M-1) {
      cout << d << "\n";
      return;
    }

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
      if(map[ny][nx] == 0 && !visited[ny][nx][w]) {
        visited[ny][nx][w] = true;
        q.push({ny, nx, d + 1, w});
      } else if(map[ny][nx] == 1 && !visited[ny][nx][w-1]) {
        if(w < K) {
          // 벽을 부순다.
          visited[ny][nx][w + 1] = true;
          q.push({ny, nx, d + 1, w + 1});
        }
      }
    }
  }

  cout << "-1\n";
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M >> K;
  for (int i = 0; i < N; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < str.length(); j++) {
      map[i][j] = str[j] - '0';
    }
  }

  bfs();
  return 0;
}