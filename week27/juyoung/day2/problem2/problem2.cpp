#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001
#define INF 1e18
using namespace std;

int N, M;
int in_sight[MAX];
vector<pair<int, int>> adjList[MAX];
long long dist[MAX];

void dijkstra() {
  priority_queue<pair<long long, int>> pq;

  pq.push({0, 0});
  dist[0] = 0;

  while(!pq.empty()) {
    long long d = -pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if(dist[node] < d) continue;

    for (int i = 0; i < adjList[node].size(); i++) {
      int next = adjList[node][i].first;
      long long cost = adjList[node][i].second;
      long long new_cost = d + cost;

      if(in_sight[next] && next != N-1) continue;
      if(new_cost < dist[next]) {
        dist[next] = new_cost;
        pq.push({-new_cost, next});
      }
    }
  }
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> in_sight[i];
    dist[i] = INF;
  }

  for (int i = 0; i < M; i++) {
    int a, b, t;
    cin >> a >> b >> t;
    adjList[a].push_back({b, t});
    adjList[b].push_back({a, t});
  }

  dijkstra();

  if(dist[N-1] == INF) cout << "-1\n";
  else cout << dist[N-1] << "\n";

  return 0;
}