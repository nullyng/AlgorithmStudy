#include <iostream>
using namespace std;

int know[51];
int party[51][51];
int root[51];

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
  int N, M, cnt;

  cin >> N >> M;
  for (int i = 1; i <= N; i++) root[i] = i;

  cin >> cnt;
  for (int i = 0; i < cnt; i++) cin >> know[i];

  for (int i = 0; i < M; i++) {
    int num;
    cin >> num;
    for (int j = 0; j < num; j++) {
      cin >> party[i][j];
      Union(party[i][0], party[i][j]);
    }
  }

  int answer = M;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < cnt; j++) {
      if(Find(party[i][0]) == Find(know[j])) {
        answer--;
        break;
      }
    }
  }

  cout << answer << "\n";
  return 0;
}