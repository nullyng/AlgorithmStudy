#include <iostream>
using namespace std;

int N, M;
int root[1000001];

int Find(int x) {
  if(x == root[x]) return x;
  return root[x] = Find(root[x]);
}

void Union(int x, int y) {
  x = Find(x);
  y = Find(y);
  if(x!=y) root[y] = x;
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  for (int i = 0; i <= N; i++) root[i] = i;

  for (int i = 0; i < M; i++) {
    int op, a, b;
    cin >> op >> a >> b;
    if (op == 0)
      Union(a, b);
    else {
      if (Find(a) == Find(b)) cout << "YES\n";
      else cout << "NO\n";
    }
  }

  return 0;
}