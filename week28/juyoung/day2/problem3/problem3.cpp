#include <iostream>
#include <queue>
#include <vector>
#define MAX 100001
using namespace std;

int N, K;
bool visited[MAX];
int dist[MAX];
int memo[MAX];
int answer;
vector<int> path;

void bfs() {
  queue<int> q;

  q.push(N);
  visited[N] = true;

  while(!q.empty()) {
    int curr = q.front();
    q.pop();

    int dy[3] = {curr * 2, curr - 1, curr + 1};
    for (int i = 0; i < 3; i++) {
      int next = dy[i];

      if(0<=next && next<=100000 && !visited[next]) {
        q.push(next);
        visited[next] = true;
        dist[next] = dist[curr] + 1; // dist에 이동 거리를 기록한다.
        memo[next] = curr; // memo에는 이전 위치를 저장하여 경로를 기록한다.
      }
      if(next == K) {
        answer = dist[next];
        return;
      }
    }
  }
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> K;

  if(N==K) cout << "0\n" << N << "\n";
  else {
    bfs();
    cout << answer << "\n";
    // memo를 거슬러 올라가며 경로를 path에 추가한다.
    path.push_back(K);
    for (int i = 0; i<answer; i++)  {
      path.push_back(memo[K]);
      K = memo[K];
    }
    for (int i = path.size() - 1; i >= 0; i--)
      cout << path[i] << " ";
    cout << "\n";
  }

  return 0;
}