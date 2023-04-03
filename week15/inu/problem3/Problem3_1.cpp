#include <iostream>
#define MAX 1000000

using namespace std;

long long sum[MAX + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int T, N;

  for(int i = 1; i <= MAX; i++) {
    for(int j = 1; i * j <= MAX; j++) {
      sum[i * j] += i;
    }

    sum[i] += sum[i - 1];
  }

  cin >> T;

  for(int t = 0; t < T; t++) {
    cin >> N;
    cout << sum[N] << '\n';
  }

  return 0;
}