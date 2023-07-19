#include <iostream>
#define INF 1e9
using namespace std;

int N;
int dist[101][101];

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  
  cin >> N;
  for(int i=1; i<=N; i++) {
      for(int j=1; j<=N; j++) {
          cin >> dist[i][j];
          if(dist[i][j] == 0) dist[i][j] = INF;
      }
  }
  
  for(int k=1; k<=N; k++) {
      for(int i=1; i<=N; i++) {
          for(int j=1; j<=N; j++) {
              if(dist[i][j] > dist[i][k]+dist[k][j])
                  dist[i][j] = dist[i][k]+dist[k][j];
          }
      }
  }
  
  for(int i=1; i<=N; i++) {
      for(int j=1; j<=N; j++) {
          if(dist[i][j] != INF) cout << "1 ";
          else cout << "0 ";
      }
      cout << "\n";
  }

  return 0;
}