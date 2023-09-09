#include <iostream>
using namespace std;

int n, m;
int root[1000001];

int Find(int x) {
  if(root[x] == x) return x;
  return root[x] = Find(root[x]);
}

void Union(int x, int y) {
  x = Find(x);
  y = Find(y);

  root[y] = x;
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  for(int i = 1; i <= n; i++) root[i] = i;

  for (int i = 0; i < m; i++) {
    int op, a, b;
    cin >> op >> a >> b;
    if(op == 0) {
      // 두 집합을 합친다.
      Union(a, b);
    } else {
      // 같은 집합인지 확인한다.
      if(Find(a) == Find(b)) cout << "YES\n";
      else cout << "NO\n";
    }
  }

  return 0;
}