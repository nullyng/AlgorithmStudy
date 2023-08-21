#include <iostream>
using namespace std;

int N;
int num, sum, cnt;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> num;
    sum += num;
    cnt += num / 2;
  }

  if(sum%3 != 0) cout << "NO\n";
  else {
    sum /= 3;
    if(cnt >= sum) cout << "YES\n";
    else cout << "NO\n";
  }

  return 0;
}