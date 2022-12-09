#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
vector<int> friends[2000];
bool visited[2000];
bool flag;

void dfs(int x, int d) {
  if (d >= 5) {
    flag = 1;
    return;
  };

  int result = 0;
  for (int i = 0; i < (int)friends[x].size(); i++) {
    int next = friends[x][i];
    
    if (visited[next]) continue;
    visited[next] = true;
    dfs(next, d+1);
    if(flag) break;
    visited[next] = false;
  }

  return;
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    friends[a].push_back(b);
    friends[b].push_back(a);
  }

  for (int i = 0; i < N; i++) {
    memset(visited, false, sizeof(visited));
    visited[i] = true;
    dfs(i, 1);
    if(flag) break;
  }

  cout << flag << "\n";

  return 0;
}