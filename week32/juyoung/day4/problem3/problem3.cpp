#include <iostream>
using namespace std;

int N;
int numbers[101];
long long dp[101][21]; // n번째 등식까지의 결과가 k인 경우의 수

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for (int i = 1; i <= N; i++) cin >> numbers[i];

  // 1번째 등식까지의 결과가 1번째 수인 경우의 수는 1개이다.
  dp[1][numbers[1]] = 1;

  // 2번째 등식부터 N-1번째 등식까지 살펴본다.
  for (int i = 2; i <= N - 1; i++) {
    for (int j = 0; j <= 20; j++) {
      if(dp[i-1][j] == 0) continue;

      // 이전 등식까지의 결과가 j일 때 j와 현재 수를 더한 값에 따라
      // 이전 결과+현재 수가 20보다 작거나 같으면 올바른 등식이므로 경우의 수 카운트
      if(j+numbers[i]<=20) dp[i][j+numbers[i]] += dp[i-1][j];
      // 이전 결과-현재 수가 0보다 크거나 같으면 올바른 등식이므로 경우의 수 카운트
      if(j-numbers[i]>=0) dp[i][j-numbers[i]] += dp[i-1][j];
    }
  }

  // N-1번째 등식까지의 결과가 마지막 수와 같은 경우의 수를 출력한다.
  cout << dp[N - 1][numbers[N]] << "\n";
  return 0;
}