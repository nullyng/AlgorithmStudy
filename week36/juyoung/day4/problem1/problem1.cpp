#include <iostream>
#include <vector>
#include <tuple>
#define MAX 51
using namespace std;

int N, M;
int grid[MAX][MAX];
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
vector<pair<int, int>> clouds;
int answer = 0;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) cin >> grid[i][j];
  }

  // 초기 구름
  clouds.push_back({N, 1});
  clouds.push_back({N, 2});
  clouds.push_back({N-1, 1});
  clouds.push_back({N-1, 2});

  int dir, s;
  while(M--) {
    cin >> dir >> s;
    s = s % N;
    
    int moveY = dy[dir-1]*s;
    int moveX = dx[dir-1]*s;

    // 물을 복사하는 곳과 얼만큼 복사할지를 저장하는 배열
    // 이 배열을 바탕으로 기존 격자를 업데이트 한다.
    vector<tuple<int, int, int>> copyList;
    // 이전에 구름이 존재했던 곳인지 저장하는 배열
    // 구름이 있던 곳은 새로운 구름을 생성할 수 없다.
    vector<vector<bool>> isThereClouds(N+1, vector<bool>(N+1, false));

    // 구름을 이동시키고 비를 1씩 내린다.
    for (int i = 0; i < clouds.size(); i++) {
      // 구름을 이동시킨다.
      clouds[i].first += moveY;
      clouds[i].second += moveX;

      if(clouds[i].first <= 0) clouds[i].first += N;
      else if(clouds[i].first > N) clouds[i].first %= N;

      if(clouds[i].second <= 0) clouds[i].second += N;
      else if(clouds[i].second > N) clouds[i].second %= N;

      // 이동한 칸에 비를 1만큼 내린다.
      grid[clouds[i].first][clouds[i].second]++;
      isThereClouds[clouds[i].first][clouds[i].second] = true;
    }

    // 복사할 물의 양을 구한다.
    for (int i = 0; i < clouds.size(); i++) {
      int waterSum = 0;
      
      for (int d = 1; d < 8; d += 2) {
        int diagonalY = clouds[i].first + dy[d];
        int diagonalX = clouds[i].second + dx[d];

        // 물 복사에서는 경계를 넘어가는 건 취급하지 않는다.
        if(diagonalY<=0 || diagonalY>N || diagonalX<=0 || diagonalX>N) continue;
      
        if(grid[diagonalY][diagonalX] > 0) waterSum++;
      }
      if(waterSum > 0) copyList.push_back({clouds[i].first, clouds[i].second, waterSum});
    }

    // 격자를 업데이트한다.
    for (int i = 0; i < copyList.size(); i++) {
      int y = get<0>(copyList[i]);
      int x = get<1>(copyList[i]);
      int w = get<2>(copyList[i]);

      grid[y][x] += w;
    }

    // 구름을 초기화, 갱신한다.
    clouds.clear();
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if(grid[i][j] >= 2) {
          if(isThereClouds[i][j]) continue;
          clouds.push_back({i, j});
          grid[i][j] -= 2;
        }
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      answer += grid[i][j];
    }
  }

  cout << answer << "\n";
  return 0;
}