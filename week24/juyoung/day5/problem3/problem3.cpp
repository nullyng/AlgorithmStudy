#include <iostream>
using namespace std;

char star[3072][6143];

void print(int N, int x, int y) {
  if(N==3) {
      star[y][x] = '*';
      
      star[y+1][x-1] = '*';
      star[y+1][x+1] = '*';
      
      star[y+2][x-2] = '*';
      star[y+2][x-1] = '*';
      star[y+2][x] = '*';
      star[y+2][x+1] = '*';
      star[y+2][x+2] = '*';
  } else {
      print(N/2, x, y);
      print(N/2, x-N/2, y+N/2);
      print(N/2, x-N/2+N, y+N/2);
  }
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  
  int N;
  cin >> N;
  
  for(int i=0; i<N; i++) {
      for(int j=0; j<2*N-1; j++) {
          star[i][j] = ' ';
      }
  }
  
  print(N, N-1, 0);
  
  for(int i=0; i<N; i++) {
      for(int j=0; j<2*N-1; j++) {
          cout << star[i][j];
      }
      cout << "\n";
  }

  return 0;
}
