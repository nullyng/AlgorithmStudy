#include <iostream>
using namespace std;

int main() {
  int N, temp;
  int cnt = 0;

  cin >> N;
  temp = N;

  do {
    int sip = temp / 10;
    int il = temp % 10;

    temp = il * 10 + (sip + il) % 10;
    cnt++;
  } while (N != temp);

  cout << cnt << "\n";
  return 0;
}