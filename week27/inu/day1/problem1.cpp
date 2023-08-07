#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 100000;
const long long INF = 10000000000;

typedef struct Edge {
  int v;
  long long t;
}Edge;

int N, M;
bool isVisible[MAX_N];
long long dist[MAX_N];
vector<vector<Edge>> graph;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;

  for(int i = 0; i < N; i++) {
    cin >> isVisible[i];
    dist[i] = INF;
  }
  
  graph.assign(N, vector<Edge>());
  
  for(int i = 0; i < M; i++) {
    int u, v, t;
    cin >> u >> v >> t;

    graph[u].push_back({v, t});
    graph[v].push_back({u, t});
  }

  priority_queue<pair<long long, int>> pq;
  pq.push({0, 0});
  dist[0] = 0;

  while(!pq.empty()) {
    int u = pq.top().second;
    long long t = -pq.top().first;
    pq.pop();

    if(t > dist[u]) continue;

    for(int i = 0; i < (int)graph[u].size(); i++) {
      int v = graph[u][i].v;
      int cost = graph[u][i].t;

      if(v != N - 1 && isVisible[v]) continue;

      if(dist[v] > dist[u] + cost) {
        dist[v] = dist[u] + cost;
        pq.push({-dist[v], v});
      }
    }
  }

  if(dist[N - 1] == INF) 
    dist[N - 1] = -1;
  
  cout << dist[N - 1];

  return 0;
}