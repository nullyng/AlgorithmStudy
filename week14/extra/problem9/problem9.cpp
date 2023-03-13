#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int twoD[500][500];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int H, W;
  int sum = 0;

  cin >> H >> W;

  for(int i = 0; i < W; i++) {
    int h;
    cin >> h;

    for(int j = 0; j < h; j++)
      twoD[j][i] = 1;
  }

  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; ) {
      if(twoD[i][j] == 0) {
        j++;
        continue;
      }

      int subSum = 0;
      int idx = j + 1;

      while(idx < W && twoD[i][idx] == 0) {
        subSum++;
        idx++;
      }

      if(idx == W && twoD[i][idx - 1] == 0) subSum = 0;

      sum += subSum;
      j = idx;
    }
  }

  cout << sum;

  return 0;
}
