#include <iostream>
#include <algorithm>
using namespace std;

int N;
pair<int, int> egg[9];
int answer;

void solution(int idx) {
  if(idx >= N) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
      if(egg[i].first <= 0) cnt++;
    }
    answer = max(answer, cnt);
    return;
  }

  if(egg[idx].first <= 0) {
    solution(idx + 1);
    return;
  }

  bool isAllBroken = true;

  for (int i = 0; i < N; i++) {
    // 자기 자신이거나 이미 깨진 계란이면 건너뜀
    if(i == idx || egg[i].first <= 0) continue;
    isAllBroken = false;

    // 서로 부딪혀서 내구도 감소
    egg[i].first -= egg[idx].second;
    egg[idx].first -= egg[i].second;

    solution(idx + 1);

    // 다시 원래대로 돌리기
    egg[i].first += egg[idx].second;
    egg[idx].first += egg[i].second;
  }

  if(isAllBroken) solution(N);
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for (int i = 0; i < N; i++) {
    int hp, weight;
    cin >> hp >> weight;
    egg[i] = {hp, weight};
  }

  solution(0);

  cout << answer << "\n";
  return 0;
}