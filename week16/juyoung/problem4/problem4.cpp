#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[1001];
int dp1[1001], dp2[1001];
int answer;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];

  for (int i = 1; i <= N; i++) {
    dp1[i] = 1;
    for (int j = 1; j < i; j++) {
      if(A[j] < A[i] && dp1[i] < dp1[j]+1) {
        dp1[i] = dp1[j] + 1;
      }
    }
  }

  for (int i = N; i >= 1; i--) {
    dp2[i] = 1;
    for (int j = N; j > i; j--) {
      if(A[j] < A[i] && dp2[i] < dp2[j]+1) {
        dp2[i] = dp2[j] + 1;
      }
    }
  }

  for (int i = 1; i <= N; i++)
    answer = max(answer, dp1[i] + dp2[i] - 1);

  cout << answer << "\n";
  return 0;
}