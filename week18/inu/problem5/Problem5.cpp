#include <iostream>
#define MAX 2001

using namespace std;

int parent[MAX];
int enemy[MAX];

int Find(int u) {
  if(parent[u] == u) return u;
  return parent[u] = Find(parent[u]);
}

void Union(int u, int v) {
  u = Find(u);
  v = Find(v);

  if(u != v) parent[u] = v;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N, M;
  cin >> N >> M;

  for(int i = 1; i < MAX; i++)
    parent[i] = i;

  int result = 1;

  for(int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;

    a = Find(a);
    b = Find(b);

    if(a == b) {
      result = 0;
      break;
    }

    int& aE = enemy[a];
    int& bE = enemy[b];

    if(aE) Union(aE, b);
    else aE = b;

    if(bE) Union(bE, a);
    else bE = a;
  }

  cout << result;

  return 0;
}