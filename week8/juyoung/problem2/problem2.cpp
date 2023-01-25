#include <iostream>
#include <vector>
#include <tuple>
#define INF 1e9
using namespace std;

int N, M;
int A, B;
int dist[101][101];
int comb[2];
int p1, p2, answer = INF;

void makeComb(int idx, int cnt) {
  if(cnt == 2) {
    int time = 0;

    for (int i = 1; i <= N; i++) {
      if(comb[0] == i || comb[1] == i) continue;
      time += min(dist[comb[0]][i], dist[comb[1]][i]) * 2;
    }

    if(answer > time) {
      answer = time;
      p1 = comb[0];
      p2 = comb[1];
    }

    return;
  }

  for (int i = idx; i <= N; i++) {
    comb[cnt] = i;
    makeComb(i + 1, cnt + 1);
  }
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++)
      dist[i][j] = INF;
  }
  for (int i = 1; i <= M; i++) {
    cin >> A >> B;
    dist[A][B] = 1;
    dist[B][A] = 1;
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

  makeComb(1, 0);
  cout << p1 << " " << p2 << " " << answer << "\n";

  return 0;
}