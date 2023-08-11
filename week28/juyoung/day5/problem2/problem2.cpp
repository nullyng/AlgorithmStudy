#include <iostream>
#include <algorithm>
using namespace std;

int M, N, L;
int gun[100001];
int answer;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> M >> N >> L;
  for (int i = 0; i < M; i++) cin >> gun[i];

  sort(gun, gun + M);

  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;

    // y좌표가 이미 사정거리보다 크다면 사냥이 불가능하므로 건너뛴다.
    if(L < y) continue;

    int left = 0, right = M - 1;
    while(left <= right) {
      int mid = (left + right) / 2;

      // 거리를 계산했을 때 사정거리 내부에 있으면 정답을 카운트하고 탐색을 종료한다.
      if(abs(gun[mid]-x)+y <= L) {
        answer++;
        break;
      } else if(gun[mid] <= x) {
        // 만약 x좌표가 현재 사대의 좌표보다 크거나 같다면, 사대의 좌표를 키워야 현재 x좌표와 가까워진다.
        left = mid + 1;
      } else {
        // 그렇지 않다면 사대의 좌표를 줄여야 현재 x좌표와 가까워진다.
        right = mid - 1;
      }
    }
  }

  cout << answer << "\n";
  return 0;
}