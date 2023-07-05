#include <iostream>
using namespace std;

int N;
int paper[129][129];
int white, blue;

void divide(int y, int x, int size) {
  int color = paper[y][x];
  bool flag = true;

  for (int i = y; i < y + size; i++) {
    for (int j = x; j < x + size; j++) {
      if(paper[i][j] != color) {
        flag = false;
        break;
      }
    }
    if(!flag) break;
  }

  if(flag) {
    if(color) blue++;
    else white++;
  } else {
    divide(y, x, size / 2);
    divide(y, x + size / 2, size / 2);
    divide(y + size / 2, x, size / 2);
    divide(y + size / 2, x + size / 2, size / 2);
  }
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> paper[i][j];
    }
  }

  divide(0, 0, N);

  cout << white << "\n" << blue << "\n";
  return 0;
}