#include <iostream>
using namespace std;

int N;
long long dp[31][31]; // 한조각이 w개, 반조각이 h개 있을 때

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  for (int h = 0; h <= 30; h++) dp[0][h] = 1;

  for (int w = 1; w <= 30; w++) {
    for (int h = 0; h <= 30; h++) {
      if(h==0) dp[w][0] = dp[w-1][1];
      else dp[w][h] = dp[w-1][h+1] + dp[w][h-1];
    }
  }

  while(1) {
    cin >> N;
    if(N == 0) return 0;
    cout << dp[N][0] << "\n";
  }
}