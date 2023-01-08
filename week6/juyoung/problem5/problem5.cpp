#include <iostream>
using namespace std;

int N, M, k, v, w;
int A[10001];
int root[10001];
bool visited[10001];
int answer;

int Find(int x) {
  if(x == root[x]) return x;
  return root[x] = Find(root[x]);
}

void Union(int x, int y) {
  x = Find(x);
  y = Find(y);

  if(x != y) {
    if(A[x] < A[y]) root[y] = x;
    else root[x] = y;
  }
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M >> k;

  for (int i = 1; i <= N; i++) root[i] = i;
  for (int i = 1; i <= N; i++) cin >> A[i];
  for (int i = 0; i < M; i++) {
    cin >> v >> w;
    Union(v, w);
  }

  for (int i = 1; i <= N; i++) {
    int r = Find(i);
    if (visited[r]) continue;
    visited[r] = true;
    answer += A[r];
    if(k < answer) break;
  }

  if(k < answer) cout << "Oh no\n";
  else cout << answer << "\n";
  
  return 0;
}