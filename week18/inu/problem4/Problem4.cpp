#include <iostream>
#define MAX 1000001

using namespace std;

int parent[MAX];
int height[MAX];

void init() {
  for(int i = 1; i < MAX; i++) {
    parent[i] = i;
    height[i] = 1;
  }
}

void swap(int& u, int& v) {
  int temp = u;
  u = v;
  v = temp;
}

int Find(int u) {
  if(parent[u] == u) return u;
  return parent[u] = Find(parent[u]);
}

void Union(int u, int v) {
  u = Find(u);
  v = Find(v);

  if(u == v) return;

  if(height[u] > height[v])
    swap(u, v);

  parent[u] = v;
  height[v] += height[u];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  init();

  int N;
  cin >> N;

  for(int i = 0; i < N; i++) {
    char r;
    cin >> r;

    if(r == 'I') {
      int a, b;
      cin >> a >> b;
      Union(a, b);
    }

    if(r == 'Q') {
      int c;
      cin >> c;
      c = Find(c);
      cout << height[c] << '\n';
    }
  }

  return 0;
}