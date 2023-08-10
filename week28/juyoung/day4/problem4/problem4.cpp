#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAX 501
using namespace std;

int N, K;
pair<int, int> point[MAX];
int dist[MAX][MAX];
int dp[MAX][MAX]; // i번째 체크포인트에 도착했을 때 그전까지 j개만큼 건너뛴 경우의 최소 거리

int solve(int p, int k) {
  if(p == 1) return 0; // 현재 체크포인트가 시작점이면 최소 거리는 0
  if(dp[p][k] != -1) return dp[p][k]; // 이미 계산된 적 있다면 그 결과를 반환

  int min_dist = 2e9;
  // 0개를 건너뛰었을 때부터 k개를 건너뛰었을 때까지, 각각의 최소 거리를 계산
  for (int i = 0; i <= k; i++) {
    // 만약 2번 체크포인트에 도착했는데(p=2) 이미 1번 건너뛴 건(i=1) 있을 수 없다.
    // 2-1-1=0, 0<1이므로 그런 경우는 계산하지 않고 건너뛴다.
    if(p-i-1 < 1) break;
    // p-i-1번 체크포인트에 도착했을 때 그전까지 k-i개만큼 건너뛴 경우의 최소 거리 + p-i-1에서 p까지 건너뛴 경우의 거리 vs. 현재의 최소 거리
    // ex) solve(3, 2)+dist[3][4]이면 2번 건너뛰어서 3번으로 갔을 때의 최소 거리 + 3번에서 4번까지의 거리
    min_dist = min(solve(p - i - 1, k - i) + dist[p - i - 1][p], min_dist);
  }

  // 0~k번 건너뛰어서 p에 도착한 거리들 중 최솟값을 dp[p][k]에 저장한다.
  return dp[p][k] = min_dist;
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    point[i] = {x, y};
  }

  memset(dp, -1, sizeof(dp));

  // 미리 좌표 간 거리를 계산하여 dist에 저장한다.
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j <= N - 1; j++) {
      dist[i + 1][j + 1] = abs(point[i].first - point[j].first) + abs(point[i].second - point[j].second);
    }
  }

  cout << solve(N, K) << "\n";
  return 0;
}