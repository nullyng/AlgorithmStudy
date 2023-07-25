#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1001], dp[1001];

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for (int i = 1; i <= N; i++) cin >> arr[i];

  for (int i = 2; i <= N; i++) {
    int maxi = arr[i];
    int mini = arr[i];
    for (int j = i - 1; j >= 0; j--) {
      maxi = max(maxi, arr[j+1]);
      mini = min(mini, arr[j+1]);
      dp[i] = max(dp[i], dp[j] + maxi - mini);
    }
  }

  cout << dp[N] << "\n";
  return 0;
}