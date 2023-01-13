#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>
#define INF 1e9*2
using namespace std;

int TC, N, M, W;
int S, E, T;
int dist[501];
bool answer;

bool bellmanford(vector<tuple<int, int, int>> &roads) {
  dist[1] = 0;

  for (int i = 1; i <= N-1; i++) {
    for (int j = 0; j < (int)roads.size(); j++) {
      int from = get<0>(roads[j]);
      int to = get<1>(roads[j]);
      int cost = get<2>(roads[j]);

      if(dist[from] == INF) continue;
      if(dist[to] > dist[from] + cost)
        dist[to] = dist[from] + cost;
    }
  }

  for (int j = 0; j < (int)roads.size(); j++) {
    int from = get<0>(roads[j]);
    int to = get<1>(roads[j]);
    int cost = get<2>(roads[j]);

    if(dist[from] == INF) continue;
    if(dist[to] > dist[from] + cost)
      return true;
  }

  return false;
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> TC;

  while(TC--) {
    cin >> N >> M >> W;
    vector<tuple<int, int, int>> roads;

    for (int i = 0; i < M; i++) {
      cin >> S >> E >> T;
      roads.push_back({S, E, T});
      roads.push_back({E, S, T});
    }
    for (int i = 0; i < W; i++) {
      cin >> S >> E >> T;
      roads.push_back({S, E, -T});
    }

    memset(dist, INF, N+1);
    answer = false;

    if(bellmanford(roads)) cout << "YES\n";  
    else cout << "NO\n";
  }

  return 0;
}