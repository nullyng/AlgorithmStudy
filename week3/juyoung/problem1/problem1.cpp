#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N, M;
  int A[100000];

  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];
  sort(A, A + N);

  cin >> M;
  for (int i = 0; i < M; i++) {
    int input;
    cin >> input;

    int low, high, mid;
    bool isThere = false;
    low = 0;
    high = N - 1;
    while (low <= high) {
      mid = (low + high) / 2;
      if(input == A[mid]) {
        isThere = true;
        break;
      }
      else if(input > A[mid]) low = mid + 1;
      else if(input < A[mid]) high = mid - 1;
    }

    if(isThere) cout << "1\n";
    else cout << "0\n";
  }

  return 0;
}