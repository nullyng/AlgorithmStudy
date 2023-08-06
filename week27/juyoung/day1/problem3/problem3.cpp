#include <iostream>
#include <algorithm>
using namespace std;

int N, C;
long long home[200001];
int answer;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> C;
  for (int i = 0; i < N; i++) cin >> home[i];

  sort(home, home + N);

  // 최소 거리와 최대 거리
  int left = 1, right = home[N - 1] - home[0];

  while(left <= right) {
    int mid = (left + right) / 2;

    // mid 이상의 거리를 가지고 있는 집의 쌍이 몇 개인지 세아린다.
    int temp = 0, count = 1;
    for (int i = temp+1; i < N; i++) {
      if(home[i] - home[temp] >= mid) {
        temp = i;
        count++;
      }
    }

    // count가 설치해야 하는 공유기 개수보다 크거나 같다면
    if(count >= C) {
      // 더 큰 거리에서 비교하기 위해 left를 옮긴다.
      answer = mid;
      left = mid + 1;
    } else {
      // 그렇지 않다면 더 작은 거리에서 비교하기 위해 right를 옮긴다.
      right = mid - 1;
    }
  }

  cout << answer << "\n";
  return 0;
}