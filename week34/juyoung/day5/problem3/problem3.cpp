#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int walkTime, walkMoney, bikeTime, bikeMoney;
int dp[101][100001]; // i를 j분 안에 지났을 때 최대로 얻을 수 있는 금액
int answer;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> K;

  for (int i = 1; i <= N; i++) {
    cin >> walkTime >> walkMoney >> bikeTime >> bikeMoney;
    if(i == 1) {
      dp[i][walkTime] = walkMoney;
      dp[i][bikeTime] = max(dp[i][bikeTime], bikeMoney);
    } else {
      for (int j = 0; j <= K; j++) {
        if(dp[i-1][j] == 0) continue;
        if(j+walkTime <= K)
          dp[i][j + walkTime] = max(dp[i][j + walkTime], dp[i - 1][j] + walkMoney);
        if(j+bikeTime <= K)
          dp[i][j + bikeTime] = max(dp[i][j + bikeTime], dp[i - 1][j] + bikeMoney);
      }
    }
  }

  for (int i = 1; i<= K; i++) answer = max(answer, dp[N][i]);
  cout << answer << "\n";
  return 0;
}