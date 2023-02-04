#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N, M, num;
  int card[500001];
  map<int, int> m;

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> card[i];
    m[card[i]]++;
  }
  sort(card, card + N);

  cin >> M;
  while(M--) {
    cin >> num;

    int low = 0;
    int high = N - 1;
    bool isThere = false;
    while (low <= high) {
      int mid = (low + high) / 2;

      if(num == card[mid]) {
        isThere = true;
        break;
      }
      else if(num < card[mid]) high = mid - 1;
      else if (num > card[mid]) low = mid + 1;
    }

    if(isThere) cout << m[num] << " ";
    else cout << "0 ";
  }

  return 0;
}