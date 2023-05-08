#include <iostream>
#include <vector>
using namespace std;

vector<int> adjList[100001];
int sum[100001];

void dfs(int node) {
  for (int i = 0; i < adjList[node].size(); i++) {
    int next = adjList[node][i];
    sum[next] += sum[node];
    dfs(next);
  }
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n, m, i, w;

  cin >> n >> m;
  for (int j = 1; j <= n; j++) {
    int p;
    cin >> p;
    if(p == -1) continue;
    adjList[p].push_back(j);
  }

  for (int j = 0; j < m; j++) {
    cin >> i >> w;
    sum[i] += w;
  }

  dfs(1);

  for (int j = 1; j <= n; j++)
    cout << sum[j] << " ";
  cout << "\n";

  return 0;
}