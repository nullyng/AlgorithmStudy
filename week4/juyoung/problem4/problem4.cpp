#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  string S, T;
  bool isAvailable = false;
  cin >> S >> T;

  while(T.length() > 0) {
    if(S == T) { 
      isAvailable = true;
      break;
    }

    char last = T[T.length() - 1];
    T = T.substr(0, T.length() - 1);
    if (last == 'B') reverse(T.begin(), T.end());
  }

  if(isAvailable) cout << "1\n";
  else cout << "0\n";

  return 0;
}