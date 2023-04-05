#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;

int root[3001];

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

  int T;
  int N, x, y, R;

  cin >> T;
  while(T--) {
    tuple<int, int, int> enemy[3001];

    cin >> N;
    for (int i = 1; i <= N; i++) {
      cin >> x >> y >> R;
      enemy[i] = {x, y, R};
      root[i] = i;
    }

    for (int i = 1; i <= N; i++) {
      int x1 = get<0>(enemy[i]);
      int y1 = get<1>(enemy[i]);
      int r1 = get<2>(enemy[i]);
      for (int j = i+1; j <= N; j++) {
        int x2 = get<0>(enemy[j]);
        int y2 = get<1>(enemy[j]);
        int r2 = get<2>(enemy[j]);
        int dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        int comp = (r1 + r2) * (r1 + r2);
        if (dist <= comp) Union(i, j);
      }
    }

    bool flag[3001];
    memset(flag, false, sizeof(flag));
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
      int r = Find(i);
      if (flag[r])
        continue;
      flag[r] = true;
      cnt++;
    }

    cout << cnt << "\n";
  }

  return 0;
}