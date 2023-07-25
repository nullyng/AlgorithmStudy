#include <iostream>
#define MOD 1000000007
using namespace std;

int n;
long long fibo[1000001];

int main() {
  cin >> n;

  fibo[0] = 0;
  fibo[1] = 1;
  for (int i = 2; i <= n; i++) fibo[i] = (fibo[i - 1] + fibo[i - 2]) % MOD;

  cout << fibo[n] << "\n";
  return 0;
}