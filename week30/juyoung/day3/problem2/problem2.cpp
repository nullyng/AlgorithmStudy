#include <iostream>
#include <cmath>
#include <vector>
#define MAX 100000
using namespace std;

// 만들 수 있는 최대 숫자가 98765이므로 10만으로 초기화
int K, M;
vector<int> prime;
bool isSumCase[MAX];
bool isMultCase[MAX];
int length;
int visited[10];
int answer;

// 에라토스테네스의 체 알고리즘으로 소수를 구한다.
void getPrime() {
  bool isPrime[MAX];
  
  for(int i=2; i<=length; i++) isPrime[i] = true;

  for (int i = 2; i * i <= length; i++) {
    if(isPrime[i]) {
      for (int j = i + i; j <= length; j+=i) {
        isPrime[j] = false;
      }
    }
  }

  for (int i = 2; i <= length; i++) {
    if(isPrime[i]) prime.push_back(i);
  }
}

// 두 개의 소수의 합 구하기
void getSumCase() {
  for (int i = 0; i<prime.size()-1; i++) {
    if(prime[i] >= length) return;
    for (int j = i + 1; j<prime.size(); j++) {
      int temp = prime[i] + prime[j];
      if (temp >= length) break;
      isSumCase[temp] = true;
    }
  }
}

// 두 개의 소수의 곱 구하기
void getMultCase() {
  // 두 개의 소수가 같아도 되므로 i와 j를 같은 범위로 지정한다.
  for (int i = 0; i<prime.size(); i++) {
    if(prime[i] >= length) return;
    for (int j = 0; j < prime.size(); j++) {
      long long temp = (long long)prime[i] * (long long)prime[j];
      if(temp >= length) break;
      isMultCase[temp] = true;
    }
  }
}

void getAnswer(int cnt, int number) {
  // K자리 수 만들고 1, 2번 조건 만족하는지 확인
  if(cnt == K) {
    int temp = number;
    while(temp%M == 0) temp /= M;

    if (isSumCase[number] && isMultCase[temp]) answer++;
    
    return;
  }

  for (int i = 0; i <= 9; i++) {
    if(cnt == 0 && i == 0 || visited[i]) continue;

    visited[i] = true;
    getAnswer(cnt + 1, number*10+i);
    visited[i] = false;
  }
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> K >> M;
  length = pow(10, K);

  getPrime(); // 소수를 구한다.
  getSumCase(); // 두 개의 소수의 합으로 나타낼 수 있는 경우를 구한다.
  getMultCase(); // M으로 나누어 떨어지지 않을 때까지 나눈 수가 두 개의 소수의 곱인 경우를 구한다.

  getAnswer(0, 0);

  cout << answer << "\n";
  return 0;
}
