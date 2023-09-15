#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue<pair<int, int>> pq; // 끝시간, 필요한 시간
int work[1000001];

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for (int i = 0; i < N; i++) {
    int T, S;
    cin >> T >> S;
    pq.push({S, T});
  }

  bool flag = true;
  while(!pq.empty()) {
    int T = pq.top().second;
    int S = pq.top().first;
    pq.pop();

    int idx = S-1;
    int cnt = 0;
    while(cnt < T && idx > 0) {
      if(work[idx--] == 1) cnt = 0;
      else cnt++;
    }

    if(cnt < T) { flag = false; break; };
    for (int i = idx+1; i < idx+1+cnt; i++) work[i] = 1;
  }

  if(flag) {
    for (int i = 1; i <= 1000001; i++) {
      if(work[i]) {
        cout << i << "\n";
        break;
      }
    }
  } else cout << "-1\n";

  return 0;
}