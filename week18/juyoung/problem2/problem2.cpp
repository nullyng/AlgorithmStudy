#include <iostream>
using namespace std;

int root[300001];

int Find(int x) {
  if(x == root[x]) return x;
  return root[x] = Find(root[x]);
}

void Union(int x, int y) {
  x = Find(x);
  y = Find(y);

  if(x<=y) root[y] = x;
  else root[x] = y;
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  for(int i = 1; i <= N; i++) root[i] = i;

  for (int i = 0; i < N - 2; i++) {
    int a, b;
    cin >> a >> b;
    Union(a, b);
  }

  int r = Find(1);
  for (int i = 2; i <= N; i++) {
    if (r != Find(root[i])) {
      cout << r << " " << i << "\n";
      break;
    }
  }

  return 0;
}