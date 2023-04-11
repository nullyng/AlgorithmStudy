#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#define INF 1e9
using namespace std;

int N, M;
bool comp[1001]; // f: A, t: B
vector<pair<int, int>> adjList[1001];
pair<int, int> dist[1001];

void dijkstra() {
  priority_queue<tuple<int, int, int>> pq; // 시간, 환승 횟수, 역 번호

  pq.push({0, 0, 0});
  dist[0] = {0, 0};

  while(!pq.empty()) {
    int cost = -get<0>(pq.top());
    int cnt = get<1>(pq.top());
    int curr = get<2>(pq.top());
    pq.pop();

    for (int i = 0; i < adjList[curr].size(); i++) {
      int next = adjList[curr][i].first;
      int new_cost = cost + adjList[curr][i].second;
      int new_cnt = cnt;

      if(comp[curr] != comp[next]) {
        new_cost += 1001;
        new_cnt++;
      }

      if(new_cost < dist[next].first) {
        dist[next].first = new_cost;
        dist[next].second = new_cnt;
        pq.push({-new_cost, new_cnt, next});
      }
    }
  }
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> comp[i];
    dist[i].first = INF;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int time;
      cin >> time;
      if(time > 0) {
        adjList[i].push_back({j, time});
        adjList[j].push_back({i, time});
      }
    }
  }

  dijkstra();

  cout << dist[M].second << " " << dist[M].first - dist[M].second * 1001 << "\n";

  return 0;
}