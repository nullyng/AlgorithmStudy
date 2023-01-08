#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

int N, M;
int A, B, C;
int S, E;
vector<tuple<int, int, int>> edge;
vector<pair<int, int>> adjList[100001];
bool visited[100001];
int root[100001];
int weight[100001];
int answer = INF;

int Find(int x) {
  if(x == root[x]) return x;
  return root[x] = Find(root[x]);
}

void Union(int x, int y) {
  x = Find(x);
  y = Find(y);
  if(x!=y) root[y] = x;
}

int dfs(int node, int cnt) {
  if(node == E) {
    for (int i = 0; i < cnt; i++) answer = min(answer, weight[i]);
    return 1;
  }

  for (int i = 0; i < (int)adjList[node].size(); i++) {
    int next = adjList[node][i].first;
    int w = adjList[node][i].second;

    if(visited[next]) continue;
    visited[next] = true;
    weight[cnt] = w;
    if(dfs(next, cnt + 1)) return 1;
  }

  return 0;
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) root[i] = i;
  for (int i = 0; i < M; i++) {
    cin >> A >> B >> C;
    edge.push_back({-C, A, B});
  }
  cin >> S >> E;

  sort(edge.begin(), edge.end());

  for (int i = 0; i < (int)edge.size(); i++) {
    C = -get<0>(edge[i]);
    A = get<1>(edge[i]);
    B = get<2>(edge[i]);

    if(Find(A) == Find(B)) continue;
    Union(A, B);
    adjList[A].push_back({B, C});
    adjList[B].push_back({A, C});
  }

  visited[S] = true;
  dfs(S, 0);

  cout << answer << "\n";
  return 0;
}