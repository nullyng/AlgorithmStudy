#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

int N, H;
int t, a, h;
vector<tuple<int, int, int>> room;

bool battle(long long mid) {
  long long hp = mid;
  long long attack = H;

  for (int i = 0; i < N; i++) {
    int t = get<0>(room[i]);
    int a = get<1>(room[i]);
    int h = get<2>(room[i]);

    if(t == 1) {
      // 몬스터보다 먼저 죽는다면 false 반환
      if(((h-1)/attack) > ((hp-1)/a)) return false;
      hp -= (h - 1) / attack * a;
    }
    else {
      attack += a;
      hp = min(hp + h, mid);
    }
  }

  return true;
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> H;
  for (int i = 0; i < N; i++) {
    cin >> t >> a >> h;
    room.push_back({t, a, h});
  }

  long long left = 1, right = 1e18;
  long long answer = -1;

  while(left <= right) {
    long long mid = (left + right) / 2;

    if(battle(mid)) {
      answer = mid;
      right = mid - 1;
    } else
      left = mid + 1;
  }

  cout << answer << "\n";
  return 0;
}