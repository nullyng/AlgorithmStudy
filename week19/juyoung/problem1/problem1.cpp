#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int N, M, K;
int U, V, C;
int itv;
vector<pair<int, int>> adjList[100001];
priority_queue<pair<ll, int>> pq;
ll dist[100001];
int an;
ll ad;

void dijkstra() {
  while(!pq.empty()) {
    ll d = -pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if(dist[node] < d) continue;

    for (int i = 0; i < (int)adjList[node].size(); i++) {
      int next = adjList[node][i].first;
      ll cost = adjList[node][i].second;
      ll new_cost = d + cost;

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

  cin >> N >> M >> K;
  for (int i = 0; i < M; i++) {
    cin >> U >> V >> C;
    adjList[V].push_back({U, C});
  }

  for(int i = 1; i <= N; i++) dist[i] = __LONG_LONG_MAX__;

  for (int i = 0; i < K; i++) {
    cin >> itv;
    pq.push({0, itv});
    dist[itv] = 0;
  }

  dijkstra();

  for (int i = 1; i <= N; i++) {
    if(ad < dist[i]) {
      ad = dist[i];
      an = i;
    }
  }

  cout << an << "\n" << ad << "\n";
  return 0;
}