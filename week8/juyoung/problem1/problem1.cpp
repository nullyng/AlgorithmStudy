#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

int V, E;
int a, b, c;
int dist[401][401];
int answer = INF;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> V >> E;
  for (int i = 1; i <= V; i++) {
    for (int j = 1; j <= V; j++) {
      dist[i][j] = INF;
    }
  }

  for (int i = 0; i < E; i++) {
    cin >> a >> b >> c;
    dist[a][b] = c;
  }

  for (int k = 1; k <= V; k++) {
    for (int i = 1; i <= V; i++) {
      for (int j = 1; j <= V; j++) {
        if(dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
          if(i==j) answer = min(answer, dist[i][j]);
        }
      }
    }
  }

  if(answer == INF) cout << "-1\n";
  else cout << answer << "\n";

  return 0;
}