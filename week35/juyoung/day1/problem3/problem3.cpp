#include <iostream>
#define INF 1e9
using namespace std;

int N, M;
int dist[1001][1001];

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++)
      if(i!=j) dist[i][j] = INF;
  }

  for (int i = 0; i < N-1; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      dist[a][b] = c;
      dist[b][a] = c;
    }

  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if(dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    cout << dist[a][b] << "\n";
  }

  return 0;
}