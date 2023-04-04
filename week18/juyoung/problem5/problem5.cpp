#include <iostream>
using namespace std;

int partner[2001];
int enemy[2001];

int Find(int x) {
  if(partner[x] == x) return x;
  return partner[x] = Find(partner[x]);
}

void Union(int x, int y) {
  x = Find(partner[x]);
  y = Find(partner[y]);

  if(x!=y) partner[y] = x;
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N, M;
  int A, B;
  int answer = 1;

  cin >> N >> M;
  for (int i = 1; i <= N; i++) partner[i] = i;

  for (int i = 0; i < M; i++) {
    cin >> A >> B;

    A = Find(A);
    B = Find(B);

    if(A==B) {
      answer = 0;
      break;
    }

    int eofa = enemy[A];
    int eofb = enemy[B];

    if(eofa) Union(eofa, B);
    else enemy[A] = B;

    if(eofb) Union(eofb, A);
    else enemy[B] = A;
  }

  cout << answer << "\n";
  return 0;
}