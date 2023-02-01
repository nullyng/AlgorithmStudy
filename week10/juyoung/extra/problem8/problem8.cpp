#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int K, N;
  long long line[10001];
  long long max_length = 0;

  cin >> K >> N;
  for (int i = 0; i < K; i++) {
    cin >> line[i];
    if(max_length < line[i]) max_length = line[i];
  }

  long long low = 1;
  long long high = max_length;
  long long answer = 0;
  long long mid = max_length;
  while (low <= high) {
    int cnt = 0;
    for (int i = 0; i < K; i++)
      cnt += line[i] / mid;

    if (cnt >= N) {
      answer = max(answer, mid);
      low = mid + 1;
    }
    else
      high = mid - 1;

    mid = (low + high) / 2;
  }

  cout << answer << "\n";
  return 0;
}