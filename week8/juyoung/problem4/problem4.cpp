#include <iostream>
#define INF 1e9
using namespace std;

int N, T, M;
int s, x, y;
int A, B;
pair<int, int> city[1001];
int dist[1001][1001];
int special[1001];

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> T;
  for (int i = 1; i <= N; i++) {
    cin >> s >> x >> y;
    city[i] = {x, y};
    if (s) special[i] = true;

    for (int j = 1; j <= N; j++) dist[i][j] = INF;
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if(i==j) { 
        dist[i][j] = 0;
        continue;
      }

      int d = abs(city[i].first - city[j].first) + abs(city[i].second - city[j].second);
      
      if (special[i] && special[j])
        dist[i][j] = min(T, d);
      else
        dist[i][j] = d;
    }
  }

  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if(dist[i][j] > dist[i][k] + dist[k][j])
          dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }

  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> A >> B;
    cout << dist[A][B] << "\n";
  }

  return 0;
}