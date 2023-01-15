#include <iostream>
#include <vector>
#include <tuple>
#define INF 1e9
using namespace std;

int N, M;
int A, B, C;
long long dist[501];
vector<tuple<int, int, int>> bus;

void bellmanford() {
  dist[1] = 0;

  for (int i = 1; i <= N - 1; i++) {
    for (int j = 0; j < (int)bus.size(); j++) {
      int from = get<0>(bus[j]);
      int to = get<1>(bus[j]);
      int time = get<2>(bus[j]);

      if(dist[from] == INF) continue;
      if (dist[to] > dist[from] + time)
        dist[to] = dist[from] + time;
    }
  }

  // 음수 사이클이 있는지 확인
  for (int i = 0; i < (int)bus.size(); i++) {
    int from = get<0>(bus[i]);
    int to = get<1>(bus[i]);
    int time = get<2>(bus[i]);

    if(dist[from] == INF) continue;
    if (dist[to] > dist[from] + time) {
      cout << "-1\n";
      return;
    }
  }

  for (int i = 2; i <= N; i++) {
    if(dist[i] == INF) cout << "-1\n";
    else cout << dist[i] << "\n";
  }
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) dist[i] = INF;
  for (int i = 0; i < M; i++) {
    cin >> A >> B >> C;
    bus.push_back({A, B, C});
  }

  bellmanford();

  return 0;
}