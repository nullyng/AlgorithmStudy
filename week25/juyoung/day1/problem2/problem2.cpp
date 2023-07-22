#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;

int n, m;
int a, b, c;
int dist[101][101];

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  
  cin >> n >> m;
  for(int i=1; i<=n; i++) {
      for(int j=1; j<=n; j++) {
          dist[i][j] = INF;
      }
  }
  
  for(int i=0; i<m; i++) {
      cin >> a >> b >> c;
      dist[a][b] = min(dist[a][b], c);
  }
  
  for(int k=1; k<=n; k++) {
      for(int i=1; i<=n; i++) {
          for(int j=1; j<=n; j++) {
              if(i==j) continue;
              if(dist[i][j] > dist[i][k]+dist[k][j])
                  dist[i][j] = dist[i][k]+dist[k][j];
          }
      }
  }
  
  for(int i=1; i<=n; i++) {
      for(int j=1; j<=n; j++) {
          if(dist[i][j] == INF) cout << "0 ";
          else cout << dist[i][j] << " ";
      }
      cout << "\n";
  }

  return 0;
}
