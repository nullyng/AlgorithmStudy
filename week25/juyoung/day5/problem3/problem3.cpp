#include <iostream>
#include <cstring>
using namespace std;

int N;
int arr[5001];
int dp[5001][5001];

int pal(int l, int r) {
  if(l >= r) return 0;

  int cnt = dp[l][r];
  if(cnt != -1) return cnt;

  cnt = 0;
  if(arr[l] == arr[r]) cnt = pal(l + 1, r - 1);
  else cnt = min(pal(l, r - 1), pal(l + 1, r)) + 1;

  return dp[l][r] = cnt;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  
  memset(dp, -1, sizeof(dp));
  cout << pal(0, N - 1) << "\n";

  return 0;
}