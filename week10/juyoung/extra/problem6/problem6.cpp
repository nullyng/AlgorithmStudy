#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N, M, input;
  int A[100001];

  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];
  sort(A, A + N);

  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> input;

    int left = 0;
    int right = N - 1;
    bool answer = false;
    while (left <= right) {
      int mid = (left + right) / 2;

      if(input < A[mid]) right = mid - 1;
      else if(input > A[mid]) left = mid + 1;
      else if (input == A[mid]) {
        answer = true;
        break;
      }
    }

    if(answer) cout << "1\n";
    else cout << "0\n";
  }

  return 0;
}