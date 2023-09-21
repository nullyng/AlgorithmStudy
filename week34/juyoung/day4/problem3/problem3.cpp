#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;

int N, K;
long long X[MAX];

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> X[i];

  sort(X, X + N);

  long long left = X[0];
  long long right = X[0]+K;
  long long cnt = 0;
  long long answer = 0;

  while(left <= right) {
    long long mid = (left + right) / 2;
    cnt = 0;

    for (int i = 0; i < N; i++) {
      if(mid > X[i]) cnt += (mid-X[i]);
      else break;
    }

    if(cnt > K) right = mid-1;
    else {
      answer = mid;
      left = mid + 1;
    }
  }

  cout << answer << "\n";
  return 0;
}