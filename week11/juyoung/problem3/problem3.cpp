#include <iostream>
using namespace std;

int N, M;
int dist[101][101];

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int heavy, light;
    cin >> heavy >> light;
    dist[heavy][light] = 1;
  }

  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if(dist[i][k] && dist[k][j])
          dist[i][j] = 1;
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    int answer = 0;
    for (int j = 1; j <= N; j++) {
      if(i==j) continue;
      if(!dist[i][j] && !dist[j][i]) answer++;
    }
    cout << answer << "\n";
  }

  return 0;
}