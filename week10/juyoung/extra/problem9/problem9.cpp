#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N, M;
  int tree[1000001];
  int max_height = 0;

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> tree[i];
    if(max_height < tree[i]) max_height = tree[i];
  }

  int low = 1;
  int high = max_height;
  int answer = 0;
  while(low <= high) {
    int mid = (low + high) / 2;

    long long sum = 0;
    for (int i = 0; i < N; i++) {
      if(tree[i] - mid > 0) sum += tree[i] - mid;
    }

    if(sum >= M) {
      answer = max(answer, mid);
      low = mid + 1;
    }
    else {
      high = mid - 1;
    }
  }

  cout << answer << "\n";
  return 0;
}