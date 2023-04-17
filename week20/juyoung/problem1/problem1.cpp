#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N;
  int honey[100001];
  int front[100001];
  int back[100001];

  cin >> N;
  for (int i = 0; i < N; i++) cin >> honey[i];

  front[0] = honey[0];
  for (int i = 1; i < N; i++) {
    front[i] = honey[i] + front[i - 1];
  }

  back[N - 1] = honey[N - 1];
  for (int i = N - 2; i >= 0; i--) {
    back[i] = honey[i] + back[i + 1];
  }

  // 벌→벌통←벌
  int one = 0;
  for (int i = 1; i < N-1; i++) {
    one = max(one, front[i] - honey[0] + back[i] - honey[N - 1]);
  }

  // 벌→벌→벌통
  int two = 0;
  for (int i = 1; i < N - 1; i++) {
    two = max(two, front[N - 1] - honey[0] + front[N - 1] - front[i] - honey[i]);
  }

  // 벌통←벌←벌
  int thr = 0;
  for (int i = 1; i < N - 1; i++) {
    thr = max(thr, back[0] - honey[N - 1] + back[0] - back[i] - honey[i]);
  }

  int answer = max(one, max(two, thr));
  cout << answer << "\n";

  return 0;
}