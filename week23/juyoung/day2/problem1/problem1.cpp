#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int num[9];
int list[9];
bool isSelected[10001];

void makePerm(int cnt) {
  if(cnt == M) {
    for (int i = 0; i < M; i++) cout << list[i] << " ";
    cout << "\n";
    return;
  }

  for (int i = 0; i < N; i++) {
    if(isSelected[num[i]]) continue;
    list[cnt] = num[i];
    isSelected[num[i]] = true;
    makePerm(cnt + 1);
    isSelected[num[i]] = false;
  }
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> num[i];
  sort(num, num + N);

  makePerm(0);
  
  return 0;
}