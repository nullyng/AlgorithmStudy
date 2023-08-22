#include <iostream>
#include <queue>
#include <tuple>
#define MAX 2000
using namespace std;

int S;
bool visited[MAX][MAX]; // 화면의 이모티콘 개수, 클립보드의 이모티콘 개수
 
int bfs() {
  queue<tuple<int, int, int>> q; // 화면의 이모티콘 개수, 클립보드의 이모티콘 개수, 시간
  q.push({1, 0, 0});
  visited[1][0] = true;

  while(!q.empty()) {
    int display = get<0>(q.front());
    int clipboard = get<1>(q.front());
    int time = get<2>(q.front());
    q.pop();

    if(display == S) return time;

    // 1번, 3번 수행
    if (display > 0 && display < MAX) {
      if(!visited[display][display]) {
        visited[display][display] = true;
        q.push({display, display, time + 1});
      }

      if(!visited[display-1][clipboard]) {
        visited[display - 1][clipboard] = true;
        q.push({display - 1, clipboard, time + 1});
      }
    }

    // 2번 수행
    if(clipboard > 0 && display+clipboard < MAX) {
      if(!visited[display+clipboard][clipboard]) {
        visited[display + clipboard][clipboard] = true;
        q.push({display + clipboard, clipboard, time + 1});
      }
    }
  }
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> S;
  cout << bfs() << "\n";

  return 0;
}