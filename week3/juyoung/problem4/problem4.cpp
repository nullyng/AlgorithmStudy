#include <iostream>
#include <algorithm>
#define INF 9999999
using namespace std;

int N, L, R, X;
int A[15];
bool nanido[15];
int answer = 0;

void makeSubset(int cnt) {
  if(cnt == N) {
    int count = 0;
    int maxi = 0;
    int mini = INF;
    int sum = 0;
    int sub = 0;

    for (int i = 0; i < N; i++) {
      if(!nanido[i]) continue;
      count++;

      if (nanido[i]) {
        maxi = max(maxi, A[i]);
        mini = min(mini, A[i]);
        sum += A[i];
      }
    }
    sub = maxi - mini;

    if(count < 2 || sum < L || sum > R || sub < X) return;
    answer++;

    return;
  }

  nanido[cnt] = false;
  makeSubset(cnt + 1);
  nanido[cnt] = true;
  makeSubset(cnt + 1);
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> L >> R >> X;
  for (int i = 0; i < N; i++)
    cin >> A[i];

  makeSubset(0);

  cout << answer << "\n";

  return 0;
}