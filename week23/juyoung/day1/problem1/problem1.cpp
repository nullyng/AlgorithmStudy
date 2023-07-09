#include <iostream>
#include <algorithm>
using namespace std;

int num[5001];

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  
  int N;

  cin >> N;
  for (int i = 0; i < N; i++) cin >> num[i];

  int answer = 0;
  int temp = 2;
  for (int i = 1; i < N-1; i++) {
    if(num[i-1] <= num[i] && num[i] <= num[i+1]) temp = 2;
    else if(num[i-1] >= num[i] && num[i] >= num[i+1]) temp = 2;
    else temp++;

    answer = max(answer, temp);
  }

  cout << answer << "\n";
  return 0;
}