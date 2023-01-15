#include <iostream>
#include <queue>
#include <tuple>
#define INF 1e9
using namespace std;

int N, M;
char miro[101][101];
int dist[101][101];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void dijkstra() {
  priority_queue<tuple<int, int, int>> pq;

  pq.push({0, 0, 0});
  dist[0][0] = 0;

  while(!pq.empty()) {
    tuple<int, int, int> top = pq.top();
    int w = -get<0>(top);
    int y = get<1>(top);
    int x = get<2>(top);
    pq.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if(ny<0 || ny>=N || nx<0 || nx>=M) continue;

      int nw = w + miro[ny][nx] - 48;
      if(nw < dist[ny][nx]) {
        dist[ny][nx] = nw;
        pq.push({-nw, ny, nx});
      }
    }
  }
}

int main() {
  cin >> M >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> miro[i][j];
      dist[i][j] = INF;
    }
  }

  dijkstra();
  cout << dist[N-1][M-1] << "\n";

  return 0;
}