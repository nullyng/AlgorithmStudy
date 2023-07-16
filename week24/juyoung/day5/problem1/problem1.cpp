#include <iostream>
using namespace std;

long long n, W;
long long s[15];
long long coin;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n >> W;
  for (int i = 0; i < n; i++) cin >> s[i];

  for (int i = 0; i < n-1; i++) {
    if(s[i] < s[i+1]) {
      coin = W / s[i];
      W = W % s[i];
      coin = coin * s[i + 1];
      W += coin;
    }
  }

  cout << W << "\n";
  return 0;
}