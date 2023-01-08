#include <iostream>
using namespace std;

int N, M;
int root[201];
int input;

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
  for(int i=1; i<=N; i++) root[i] = i;

  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      cin >> input;
      if(input) Union(i, j);
    }
  }

  cin >> input;
  int r = Find(input);
  int i;
  for(i=1; i<M; i++) {
    cin >> input;
    if(r != Find(input)) {
      cout << "NO\n";
      break;
    }
  }

  if(i==M) cout << "YES\n";
  return 0;
}