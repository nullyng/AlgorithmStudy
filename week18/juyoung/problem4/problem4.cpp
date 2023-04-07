#include <iostream>
#define MAX 1000001
using namespace std;

int root[MAX];
int cnt[MAX];

int Find(int x) {
  if(x == root[x]) return x;
  return root[x] = Find(root[x]);
}

void Union(int x, int y) {
  x = Find(x);
  y = Find(y);

  if(x<=y) {
    root[y] = x;
    cnt[x] += cnt[y];
    cnt[y] = 0;
  } else {
    root[x] = y;
    cnt[y] += cnt[x];
    cnt[x] = 0;
  }
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  for (int i = 1; i <= MAX; i++) {
    root[i] = i;
    cnt[i] = 1;
  }

  for (int i = 0; i < N; i++) {
    char op;
    int a, b;

    cin >> op;
    if(op == 'I') {
      cin >> a >> b;
      if(Find(a) != Find(b)) Union(a, b);
    } else if (op == 'Q') {
      cin >> a;
      cout << cnt[Find(a)] << "\n";
    }
  }

  return 0;
}