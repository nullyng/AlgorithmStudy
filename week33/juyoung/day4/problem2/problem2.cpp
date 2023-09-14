#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int N, M;
int A, B, C;
vector<int> graph[501];
int dist[501][501];

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> dist[i][j];
    }
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
    int A, B, C;
    cin >> A >> B >> C;
    if(dist[A][B] <= C) cout << "Enjoy other party\n";
    else cout << "Stay here\n";
  }

  return 0;
}