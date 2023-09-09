#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int N, L, R;
int A[51][51];
bool visited[51][51];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int answer;

int bfs(int y, int x) {
  queue<pair<int, int>> q;
  vector<pair<int, int>> v; // 인구 이동하는 위치
  int sum = 0;

  q.push({y, x});
  visited[y][x] = true;
  v.push_back({y, x});
  sum += A[y][x];

  while(!q.empty()) {
    y = q.front().first;
    x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if(ny<0 || ny>=N || nx<0 || nx>=N || visited[ny][nx]) continue;
      if(L > abs(A[ny][nx]-A[y][x]) || abs(A[ny][nx]-A[y][x]) > R) continue;

      visited[ny][nx] = true;
      q.push({ny, nx});
      v.push_back({ny, nx});
      sum += A[ny][nx];
    }
  }

  // 연합인 각 나라의 인구수를 (연합의 인구수) / (연합을 이루고 있는 칸의 개수)로 갱신한다.
  for (int i = 0; i < v.size(); i++) {
    A[v[i].first][v[i].second] = sum / v.size();
  }

  return v.size()-1;
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> L >> R;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A[i][j];
    }
  }

  int unionCnt = -1;
  while(unionCnt != 0) {
    memset(visited, false, sizeof(visited));
    unionCnt = 0;

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if(visited[i][j]) continue;
        unionCnt += bfs(i, j);
      }
    }
    
    if(unionCnt > 0) answer++;
  }

  cout << answer << "\n";
  return 0;
}