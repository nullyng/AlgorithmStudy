#include <iostream>
using namespace std;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int X, Y;
  cin >> X >> Y;

  long long heightDiff = Y - X;
  long long N = 0;

  if(heightDiff < 1) cout << "0";
  else {
    while(N * N < heightDiff) ++N;

    if(N * N - N < heightDiff) cout << N * 2 - 1;
    else cout << N * 2 - 2;
  }

  return 0;
}