#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int N;
int A[MAX];
long long answer = 2e9;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];
    
  sort(A, A + N);

  int left = 0, right = N-1;
  while (left < right) {
    int temp = A[left] + A[right];
    if(abs(temp) < abs(answer)) answer = temp;

    if(temp < 0) left++;
    else right--;
  }

  cout << answer << "\n";
  return 0;
}