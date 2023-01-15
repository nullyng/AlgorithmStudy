#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9
using namespace std;

int N, V, E;
int A, B, H;
int a, b, l;
int team[101];
vector<pair<int, int>> adjList[1001];
int answer;

void dijkstra(vector<int> &dist, int start) {
  priority_queue<pair<int, int>> pq;

  pq.push({0, start});
  dist[start] = 0;

  while(!pq.empty()) {
    int node = pq.top().second;
    int d = -pq.top().first;
    pq.pop();

    for(int i=0; i<(int)adjList[node].size(); i++) {
      int next = adjList[node][i].first;
      int cost = adjList[node][i].second;
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

  cin >> N >> V >> E;
  cin >> A >> B;
  
  for(int i=0; i<N; i++) cin >> team[i];
  for(int i=0; i<E; i++) {
    cin >> a >> b >> l;
    adjList[a].push_back({b, l});
    adjList[b].push_back({a, l});
  }

  for(int i=0; i<N; i++) {
    vector<int> dist(V+1, INF);
    dijkstra(dist, team[i]);
    if(dist[A] == INF) dist[A] = -1;
    if(dist[B] == INF) dist[B] = -1;
    answer += dist[A] + dist[B];
  }

  cout << answer << "\n";
}