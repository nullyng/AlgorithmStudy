#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

int N, M, s, e;
int parent[100001];
vector<pair<int, int>> adjList[100001];
vector<tuple<int, int, int>> edge;
bool visited[100001];
int bbr[100001];
int answer = INF;

int Find(int x) {
  if(parent[x] == x) return x;
  return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
  x = Find(x);
  y = Find(y);
  if(x!=y) parent[y] = x;
}

int dfs(int node, int cnt) {
  if(node == e) {
    for (int i = 0; i < cnt; i++)
      answer = min(answer, bbr[i]);
    return -1;
  }

  for (int i = 0; i < (int)adjList[node].size(); i++) {
    int next = adjList[node][i].first;
    int k = adjList[node][i].second;
    
    if(visited[next]) continue;
    visited[next] = true;
    bbr[cnt] = k;
    if (dfs(next, cnt + 1) == -1) return -1;
  }

  return 0;
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M >> s >> e;

  for (int i = 1; i <= N; i++) parent[i] = i;
  for (int i = 0; i < M; i++) {
    int h1, h2, k;
    cin >> h1 >> h2 >> k;
    edge.push_back({-k, h1, h2}); 
  }

  sort(edge.begin(), edge.end());

  for (int i = 0; i < (int)edge.size(); i++) {
    int k = -get<0>(edge[i]);
    int h1 = get<1>(edge[i]);
    int h2 = get<2>(edge[i]);
    
    if(Find(h1) == Find(h2)) continue;
    Union(h1, h2);
    adjList[h1].push_back({h2, k});
    adjList[h2].push_back({h1, k});
  }

  visited[s] = true;
  dfs(s, 0);

  if(answer == INF) cout << "0\n";
  else cout << answer << "\n";

  return 0;
}