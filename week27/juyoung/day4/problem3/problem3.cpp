#include <iostream>
#define MAX 41
using namespace std;

int N, M;
int vip[MAX];
int dp[MAX];

void fibonacci() {
  dp[0] = dp[1] = 1;

  for (int i = 2; i <= N; i++) 
    dp[i] = dp[i - 1] + dp[i - 2];
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  for (int i = 1; i <= M; i++) cin >> vip[i];

  fibonacci(); // N까지 미리 피보나치 수열을 계산한다.

  int answer = 1;
  for (int i = 1; i <= M; i++) {
    // 각 구간 크기의 피보나치 수열을 누적하여 곱한다.
    answer *= dp[vip[i] - vip[i - 1] - 1];
  }
  answer *= dp[N - vip[M]]; // N~마지막 vip석 구간 크기의 피보나치 수열 값도 곱한다.

  cout << answer << "\n";
  return 0;
}