#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int N, M;
vector<int> graph[10001];
bool visited[10001];
int currHacked, maxHacked;
queue<int> q;

void bfs(int n) {
  q.push(n);
  visited[n] = true;

  while(!q.empty()) {
    n = q.front();
    q.pop();

    for (int i = 0; i < graph[n].size(); i++) {
      int next = graph[n][i];
      if(visited[next]) continue;
      currHacked++;
      visited[next] = true;
      q.push(next);
    }
  }
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    graph[b].push_back(a);
  }

  vector<int> depth(N+1);
  for (int i = 1; i <= N; i++) {
    memset(visited, false, N+1);
    currHacked = 0;
    bfs(i);
    depth[i] = currHacked;
    maxHacked = max(currHacked, maxHacked);
  }

  for (int i = 1; i <= N; i++) {
    if(maxHacked == depth[i]) cout << i << " ";
  }

  cout << "\n";
  return 0;
}