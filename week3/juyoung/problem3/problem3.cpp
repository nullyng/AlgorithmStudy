#include <iostream>
#include <queue>
using namespace std;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  if(N <= 9) {
    cout << N << "\n";
    return 0;
  }

  queue<long long> q;
  for (int i = 1; i <= 9; i++)
    q.push(i);
  N -= 9;

  while(!q.empty()) {
    long long num = q.front();
    q.pop();

    for (int i = 0; i < num % 10; i++) {
      long long n_num = num * 10 + i;

      if(--N == 0) {
        cout << n_num << "\n";
        return 0;
      } else {
        q.push(n_num);
      }
    }
  }

  cout << "-1\n";

  return 0;
}