#include <iostream>
using namespace std;

int T;
int n, d;
int arr[501][501];

void rotate(int angle) {
  int a = angle / 45;

  while(a--) {
    int st = 0;

    while(st < n/2) {
      int md = n / 2, ed = n - st - 1;
      int temp = arr[st][st];

      arr[st][st] = arr[md][st];
      arr[md][st] = arr[ed][st];
      arr[ed][st] = arr[ed][md];
      arr[ed][md] = arr[ed][ed];
      arr[ed][ed] = arr[md][ed];
      arr[md][ed] = arr[st][ed];
      arr[st][ed] = arr[st][md];
      arr[st][md] = temp;

      st++;
    }
  }
}

void print() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> T;
  while(T--) {
    cin >> n >> d;
    
    for(int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> arr[i][j];
      }
    }

    if(abs(d) == 360) { print(); continue; }

    if(d == 45 || d == -315) { rotate(45); }
    else if(d == 90 || d == -270) { rotate(90); }
    else if(d == 135 || d == -225) { rotate(135); }
    else if(d == 180 || d == -180) { rotate(180); }
    else if(d == 225 || d == -135) { rotate(225); }
    else if(d == 270 || d == -90) { rotate(270); }
    else if(d == 315 || d == -45) { rotate(315); }

    print();
  }

  return 0;
}