#include <iostream>
#include <string>
using namespace std;

int N;
string video[64];

void divide_conquer(int x, int y, int r) {
  char dot = video[x][y];
  for (int i = x; i < x + r; i++) {
    for (int j = y; j < y + r; j++) {
      if(video[i][j] != dot) {
        cout << "(";
        divide_conquer(x, y, r / 2);          // 왼쪽 위
        divide_conquer(x, y + r / 2, r / 2);  // 오른쪽 위
        divide_conquer(x + r / 2, y, r / 2);  // 왼쪽 아래
        divide_conquer(x + r / 2, y + r / 2, r / 2);  // 오른쪽 아래
        cout << ")";
        return;
      }
    }
  }
  cout << dot;
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> video[i];

  divide_conquer(0, 0, N);
  cout << "\n";

  return 0;
}