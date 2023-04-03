#include <iostream>
#include <vector>

using namespace std;

int N, S;
vector<int> seq;

void swap(int i, int j) {
  int temp = seq[i];
  seq[i] = seq[j];
  seq[j] = temp;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  seq.assign(N, 0);

  for(int i = 0; i < N; i++)
    cin >> seq[i];

  cin >> S;

  for(int i = 0; i < N; i++) {
    int maxValue = seq[i];
    int maxIdx = i;
    int range = min(N - 1, i + S);

    for(int j = i + 1; j <= range; j++) {
      if(seq[j] > maxValue) {
        maxValue = seq[j];
        maxIdx = j;
      }
    }

    for(int k = maxIdx; k > i; k--)
      swap(k, k - 1);
    S -= (maxIdx - i);

    if(S <= 0) break;
  }

  for(int n : seq)
    cout << n << ' ';

  return 0;
}