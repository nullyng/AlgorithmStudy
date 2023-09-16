#include <iostream>
using namespace std;

int team1[] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4};
int team2[] = {1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5};
int match[6][3], result[6][3]; // [팀][승|무|패]
int answer[4];

void backTracking(int T, int cnt) {
  if(cnt == 15) {
    // 이미 앞선 결과 중에 주어진 결과와 같은 값이 나온적이 있다면 더이상 진행x
    if(answer[T]) return;

    // 주어진 결과와 현재 결과(경우의 수)에서 하나라도 다르다면 불가능한 것이므로 return
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 3; j++) {
        if(match[i][j] != result[i][j]) return;
      }
    }

    // 주어진 결과와 현재 결과가 일치하다면 가능한 것이므로 정답 업데이트
    answer[T] = 1;
    return;
  }

  int t1 = team1[cnt];
  int t2 = team2[cnt];

  // t1 승, t2 패
  result[t1][0]++; result[t2][2]++;
  backTracking(T, cnt + 1);
  result[t1][0]--; result[t2][2]--;

  // t1 무, t2 무
  result[t1][1]++; result[t2][1]++;
  backTracking(T, cnt + 1);
  result[t1][1]--; result[t2][1]--;

  // t1 패, t2 승
  result[t1][2]++; result[t2][0]++;
  backTracking(T, cnt + 1);
  result[t1][2]--; result[t2][0]--;
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  for(int T=0; T<4; T++) { 
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 3; j++) {
        cin >> match[i][j];
      }
    }

    backTracking(T, 0);
  }

  for (int i = 0; i < 4; i++) cout << answer[i] << " ";
  return 0;
}