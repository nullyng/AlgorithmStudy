#include <iostream>
using namespace std;

int N;
int card[1001];
int lis[1001];

int binary_search(int left, int right, int target) {
  int mid;

  while(left < right) {
    mid = (left + right) / 2;

    if(lis[mid] < target) left = mid + 1;
    else right = mid;
  }

  return right;
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> card[i];

  int j = 0;
  lis[0] = card[0];
  int i = 1;

  while(i<N) {
    if(lis[j] < card[i]) {
      lis[j + 1] = card[i];
      j++;
    } else {
      int idx = binary_search(0, j, card[i]);
      lis[idx] = card[i];
    }
    i++;
  }

  cout << j + 1 << "\n";
  return 0;
}