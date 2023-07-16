#include <iostream>
#include <algorithm>
#define MAX 15
#define INF 1e9
using namespace std;

int N, L, R, X;
int A[MAX];
int selected[MAX];
int answer;

void makeComb(int idx, int cnt) {
  if(idx == N) {
    if(cnt < 2) return;

    int diff = 0, easy = INF, sum = 0;
    for (int i = 0; i < N; i++) {
      if(!selected[i]) continue;
      diff = max(diff, A[i]);
      easy = min(easy, A[i]);
      sum += A[i];
    }

    if(L <= sum && sum <= R && diff-easy >= X) answer++;

    return;
  }

  selected[idx] = false;
  makeComb(idx + 1, cnt);
  selected[idx] = true;
  makeComb(idx + 1, cnt + 1);
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> L >> R >> X;
  for (int i = 0; i < N; i++) cin >> A[i];

  makeComb(0, 0);
  cout << answer << "\n";

  return 0;
}