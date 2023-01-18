#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1e4
using namespace std;

int n, m, r;
int item[101];
int a, b, l;
int dist[101][101];

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n >> m >> r;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if(i==j) continue;
      dist[i][j] = INF;
    }
  }

  for (int i = 1; i <= n; i++) cin >> item[i];

  for (int i = 0; i < r; i++) {
    cin >> a >> b >> l;
    dist[a][b] = min(dist[a][b], l);
    dist[b][a] = min(dist[b][a], l);
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if(dist[i][j] > dist[i][k] + dist[k][j])
          dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }

  int answer = 0;
  for (int i = 1; i <= n; i++) {
    int sum = 0;
    for (int j = 1; j <= n; j++) {
      if(dist[i][j] <= m) sum += item[j];
    }

    answer = max(answer, sum);
  }

  cout << answer << "\n";
  return 0;
}