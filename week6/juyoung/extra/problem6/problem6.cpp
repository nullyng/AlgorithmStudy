#include <iostream>
using namespace std;

int G, P, g;
int root[100001];
int answer;

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

  cin >> G >> P;

  for (int i = 1; i <= G; i++) root[i] = i;
  for (int i = 0; i < P; i++) {
    cin >> g;
    int r = Find(g);

    if(r <= 0) break;
    Union(r - 1, r);
    answer++;
  }

  cout << answer << "\n";
  return 0;
}