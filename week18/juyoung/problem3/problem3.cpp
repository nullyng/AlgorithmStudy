#include <iostream>
using namespace std;

int root[1000001];
bool flag[1000001];

int Find(int x) {
  if(x == root[x]) return x;
  return root[x] = Find(root[x]);
}

void Union(int x,  int y) {
  x = Find(x);
  y = Find(y);

  if(x!=y) root[y] = x;
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  for (int i = 1; i <= N*M; i++) root[i] = i;

  for (int i = 0; i < N; i++) {
    for (int j = 1; j <= M; j++) {
      char input;
      cin >> input;
      switch(input) {
        case 'U':
          Union(M * i + j, (M * (i - 1) + j));
          break;
        case 'D':
          Union(M * i + j, (M * (i + 1) + j));
          break;
        case 'L':
          Union(M * i + j, M * i + (j - 1));
          break;
        case 'R':
          Union(M * i + j, M * i + (j + 1));
          break;
        }
    }
  }

  int answer = 0;
  for (int i = 1; i <= N * M; i++) {
    int r = Find(root[i]);
    if (flag[r]) continue;
    flag[r] = true;
    answer++;
  }

  cout << answer << "\n";
  return 0;
}