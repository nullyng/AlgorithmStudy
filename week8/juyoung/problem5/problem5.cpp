#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1e3
using namespace std;

int N, p1, p2;
int dist[51][51];
int score[51];
int s = INF, cnt;
vector<int> list;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if(i == j) continue;
      dist[i][j] = INF;
    }
  }

  while (1) {
    cin >> p1 >> p2;
    if (p1 == -1 && p2 == -1)
      break;

    dist[p1][p2] = 1;
    dist[p2][p1] = 1;
  }

  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if(dist[i][j] > dist[i][k] + dist[k][j])
          dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      score[i] = max(score[i], dist[i][j]);
    }
    s = min(s, score[i]);
  }

  for (int i = 1; i <= N; i++) {
    if(s == score[i]) {
      cnt++;
      list.push_back(i);
    }
  }

  cout << s << " " << cnt << "\n";
  for (int i = 0; i < cnt; i++)
    cout << list[i] << " ";
  cout << "\n";

  return 0;
}