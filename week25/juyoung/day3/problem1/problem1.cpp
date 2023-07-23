#include <iostream>
using namespace std;

int N, X;
int A[500001];
bool prime[1000001];
double cnt, answer;

int gcd(int a, int b) {
  int temp;
  if(a < b) {
    temp = a;
    a = b;
    b = temp;
  }

  int rest;
  while(b != 0) {
    rest = a % b;
    a = b;
    b = rest;
  }

  return a;
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];
  cin >> X;

  for (int i = 0; i < N; i++) {
    if(gcd(X, A[i]) == 1) {
      answer += A[i];
      cnt++;
    }
  }

  cout << answer / cnt << "\n";
  return 0;
}