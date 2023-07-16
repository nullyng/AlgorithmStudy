#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define INF 1e9
using namespace std;

int V, E, P;
int a, b, c;
vector<pair<int, int>> graph[5001];
int dist[5001];

void init() {
  for (int i = 1; i <= V; i++) dist[i] = INF;
}

void dijkstra(int start) {
  priority_queue<pair<int, int>> pq;

  pq.push({0, start});
  dist[start] = 0;

  while(!pq.empty()) {
    int d = -pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if(dist[node] < d) continue;

    for (int i = 0; i < graph[node].size(); i++) {
      int next = graph[node][i].first;
      int cost = graph[node][i].second;
      int new_cost = d + cost;

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

  cin >> V >> E >> P;
  for (int i = 0; i < E; i++) {
    cin >> a >> b >> c;
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }

  init();
  dijkstra(1);

  int min_to_P = dist[P];
  int min_to_V = dist[V];

  init();
  dijkstra(P);

  int P_to_V = dist[V];

  if(min_to_V == min_to_P + P_to_V) cout << "SAVE HIM\n";
  else cout << "GOOD BYE\n";

  return 0;
}