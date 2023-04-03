#include <iostream>
#include <vector>

#define MAX 100000

using namespace std;

typedef struct info {
  int w, v;
}info;

int dp[101][MAX + 1];
vector<info> bags;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  int N, K;

  cin >> N >> K;

  for(int i = 0; i < N; i++) {
    int w, v;

    cin >> w >> v;

    if(w > K) continue;
    
    bags.push_back({w, v});
  }

  int i = 1;

  for(info bag : bags) {
    int w = bag.w;
    int v = bag.v;

    for(int j = w - 1; j > 0; j--)
      dp[i][j] = dp[i - 1][j];

    for(int j = w; j <= K; j++)
      dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);

    i++;
  }

  cout << dp[i - 1][K];

  return 0;
}