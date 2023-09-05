#include <iostream>
#include <algorithm>
#define MAX 1500001
using namespace std;

int N;
int T[MAX], P[MAX];
int dp[MAX];
int answer;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;

  for (int i = 1; i <= N; i++) cin >> T[i] >> P[i];

  for (int i = 1; i <= N+1; i++) {
    int day = i + T[i];
    answer = max(answer, dp[i]);

    if(day > N+1) continue;
    dp[day] = max(dp[day], answer + P[i]);
  }

  cout << answer << "\n";
  return 0;
}