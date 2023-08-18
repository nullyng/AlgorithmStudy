#include <iostream>
#include <algorithm>
using namespace std;

int N, d, k, c;
int dish[30001];
int sushi[3001];
int answer, cnt;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> d >> k >> c;
  for (int i = 0; i < N; i++) cin >> dish[i];

  // 처음 k개의 접시에 해당하는 초밥 개수 카운트
  for (int i = 0; i < k; i++) {
    if(sushi[dish[i]]++ == 0) cnt++;
  }

  // 쿠폰 번호에 해당하는 초밥 개수 카운트
  if(sushi[c]++ == 0) cnt++;

  // 투포인터를 사용하여 왼쪽 포인터가 마지막 접시를 가리킬 때까지 반복한다.
  int left = 0, right = k - 1;
  while(left < N) {
    answer = max(answer, cnt);
    if(--sushi[dish[left++]] == 0) cnt--;
    right = (right + 1) % N;
    if(++sushi[dish[right]] == 1) cnt++;
  }

  cout << answer << "\n";
  return 0;
}