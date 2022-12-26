#include <iostream>
using namespace std;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  long long N;
  long long len = 0;  // 전체 수열의 길이
  int temp = 3;       // o가 k+2개인 수열의 길이
  cin >> N;

  while(1) {
    len = len * 2 + temp;
    if (len >= N) break;
    temp++;
  }

  while(1) {
    long long prev = (len - temp) / 2;  // 이전 문자열의 길이

    if (N <= prev) {
      // N이 앞쪽 수열 안에 있다면
      len = prev;
      temp--;
    } else if (prev < N && N <= prev + temp) {
      // N이 o가 k+2개인 수열 안에 있다면
      if(N-prev == 1) cout << "m\n";
      else cout << "o\n";
      break;
    } else if (prev + temp < N) {
      // N이 뒤쪽 수열 안에 있다면
      N -= prev + temp;
      len = prev;
      temp--;
    }
  }

  return 0;
}