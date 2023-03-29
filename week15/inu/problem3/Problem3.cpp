#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> sum;

ll getFactorsSum(int n) {
  ll result = 0;

  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      result += i;
      if(i * i != n) result += (n / i);
    }
  }

  return result;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int T, N;
  int pre = 0;

  sum.push_back(0);

  cin >> T;

  for(int t = 0; t < T; t++) {
    cin >> N;

    for(int i = pre + 1; i <= N; i++) {
      ll result = getFactorsSum(i);
      sum.push_back(sum[i - 1] + result);
    }

    cout << sum[N] << '\n';

    pre = max(pre, N);
  }

  return 0;
}