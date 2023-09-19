#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;

int xs, ys, xe, ye;
int x1, y1, x2, y2;
pair<int, int> coord[8];
long long dist[8][8];

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if(i!=j) dist[i][j] = INF;
    }
  }

  cin >> xs >> ys >> xe >> ye;
  coord[0] = {xs, ys};
  coord[1] = {xe, ye};

  for (int i = 2; i < 8; i+=2) {
    cin >> x1 >> y1 >> x2 >> y2;
    coord[i] = {x1, y1};
    coord[i + 1] = {x2, y2};
    dist[i][i + 1] = 10;
    dist[i + 1][i] = 10;
  }

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if(i==j) continue;
      long long len = abs(coord[i].first - coord[j].first) + abs(coord[i].second - coord[j].second);
      dist[i][j] = min(dist[i][j], len);
      dist[j][i] = min(dist[j][i], len);
    }
  }

  for (int k = 0; k < 8; k++) {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if(dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }

  cout << dist[0][1] << "\n";
  return 0;
}