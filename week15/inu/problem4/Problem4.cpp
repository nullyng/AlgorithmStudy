#include <iostream>
#include <vector>

#define MAX 1000000

using namespace std;

typedef long long ll;

ll sum[MAX];
ll remain[1000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N, M;
  ll answer = 0;

  cin >> N >> M;

  for(int i = 0; i < N; i++) {
    int n;
    cin >> n;
    sum[i] = n;
    if(i > 0) sum[i] += sum[i - 1];
    remain[sum[i] % M]++;
  }

  answer += remain[0];

  for(int i = 0; i < M; i++) {
    if(remain[i])
      answer += (remain[i] * (remain[i] - 1)) / 2;
  }

  cout << answer;

  return 0;
}