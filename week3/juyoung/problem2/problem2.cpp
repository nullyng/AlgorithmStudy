#include <iostream>
#include <vector>
#include <algorithm>
#define INF 999999999
using namespace std;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N, H;
  int top[100000];
  int bottom[100000];

  cin >> N >> H;
  for (int i = 0; i < N; i++) {
    if(i%2 == 0) cin >> bottom[i / 2];
    else cin >> top[i / 2];
  }

  // lower_bound, upper_bound 사용을 위한 정렬
  sort(bottom, bottom + N / 2);
  sort(top, top + N / 2);

  int answer = INF;
  int count = 0;

  // 첫번째 구간부터 차례대로 석순과 종유석 개수 구하기
  for (int h = 1; h <= H; h++) {
    int idx;
    int temp = 0;

    // 석순
    idx = lower_bound(bottom, bottom + N / 2, h) - bottom;
    temp += N / 2 - idx;

    // 종유석
    idx = upper_bound(top, top + N / 2, H - h) - top;
    temp += N / 2 - idx;

    if(temp < answer) {
      answer = temp;
      count = 1;
    } else if(temp == answer) {
      count++;
    }
  }

  cout << answer << " " << count << "\n";

  return 0;
}