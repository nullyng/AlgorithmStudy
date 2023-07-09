#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

int N, D;
int from, to, cost;
int dist[10001];
vector<pair<int, int>> graph[10001];

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> D;
  for (int i = 0; i <= D; i++) dist[i] = INF;
  for (int i = 0; i < N; i++) {
    cin >> from >> to >> cost;
    // 지름길이 의미없는 경우 || 도착 지점이 D보다 큰 경우
    if (to-from<=cost || to>D) continue;
    graph[to].push_back({from, cost});
  }

  dist[0] = 0;
  for (int i = 1; i <= D; i++) {
    if(graph[i].size() == 0) dist[i] = dist[i - 1] + 1;
    else {
      for(auto d: graph[i]) {
        dist[i] = min(dist[i], min(dist[i - 1] + 1, dist[d.first] + d.second));
      }
    }
  }

  cout << dist[D] << "\n";
  return 0;
}