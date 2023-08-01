#include <iostream>

using namespace std;

const int MAX = 1001;

int N;
int score[MAX];
int dp[MAX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  for(int i = 1; i <= N; i++)
    cin >> score[i];

  for(int i = 2; i <= N; i++) {
    int mx = 0;
    int mn = 10001;

    for(int j = i; j > 0; j--) {
      mx = max(mx, score[j]);
      mn = min(mn, score[j]);
      dp[i] = max(dp[i], dp[j - 1] + mx - mn);
    }
  }
  
  cout << dp[N];

  return 0;
}