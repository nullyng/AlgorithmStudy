#include <iostream>
#include <tuple>
#include <queue>
#define MAX 2223
#define INF 1e9
using namespace std;

int n;
int A[MAX][MAX];
int cost[MAX][MAX];
int dy[2] = {1, 0};
int dx[2] = {0, 1};

void dijkstra() {
  priority_queue<tuple<int, int, int>> pq; // 버튼 비용, y, x

  pq.push({0, 1, 1});
  cost[1][1] = 0;
  while(!pq.empty()) {
    int c = get<0>(pq.top());
    int y = get<1>(pq.top());
    int x = get<2>(pq.top());
    pq.pop();

    if(y == n && x == n) return;

    for (int i = 0; i < 2; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      int nc = c;

      if(ny<1 || ny>n || nx<1 || nx>n) continue;
      if(A[y][x] <= A[ny][nx]) nc += -(A[ny][nx]-A[y][x]+1);
      if(cost[ny][nx] >= nc) continue;
      else {
        cost[ny][nx] = nc;
        pq.push({cost[ny][nx], ny, nx});
      }
    }
  }
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> A[i][j];
      cost[i][j] = -INF;
    }
  }

  dijkstra();

  cout << -cost[n][n] << "\n";
  return 0;
}