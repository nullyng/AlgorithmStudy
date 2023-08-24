#include <iostream>
#include <queue>

using namespace std;

const int MAX = 2223;
const int INF = 10000000;

int dx[] = { 0, 1 };
int dy[] = { 1, 0 };

int N;
int dist[MAX][MAX];
int map[MAX][MAX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  for(int i = 1; i <= N; i++)
    for(int j = 1; j <= N; j++) {
      cin >> map[i][j];
      dist[i][j] = INF;
    }  

  priority_queue<pair<int, pair<int, int>>> q;
  q.push({0, {1, 1}});
  dist[1][1] = 0;

  while(!q.empty()) {
    int cost = -q.top().first;
    int x = q.top().second.first;
    int y = q.top().second.second;
    q.pop();

    if(cost > dist[x][y]) continue;

    for(int d = 0; d < 2; d++) {
      int rx = x + dx[d];
      int ry = y + dy[d];

      if(rx < 1 || rx > N || ry < 1 || ry > N) continue;

      int button = map[x][y] - map[rx][ry];
      if(button <= 0) button = -button + 1;
      else button = 0;

      if(dist[rx][ry] > cost + button) {
        dist[rx][ry] = cost + button;
        q.push({-dist[rx][ry], {rx, ry}});
      }
    }
  }

  cout << dist[N][N];

  return 0;
}