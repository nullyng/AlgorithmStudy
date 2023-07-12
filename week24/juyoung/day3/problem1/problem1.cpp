#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int answer;
  
int main() {
  cin >> N >> K;
  for(int i=1; i<=K; i++) {
      int curr = i*N;    // 현재 항
      int temp = 0;      // 뒤집은 항
      
      while(1) {
          temp += curr%10;
          curr /= 10;
          if(curr <= 0) break;
          temp *= 10;
      }
      
      answer = max(answer, temp);
  }
  
  cout << answer << "\n";
  return 0;
}
