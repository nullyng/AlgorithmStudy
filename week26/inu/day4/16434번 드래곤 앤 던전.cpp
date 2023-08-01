#include <iostream>

using namespace std;

typedef struct Room {
  long long t, a, h;
}room;

const long long MAX_ROOM = 123456;
const long long MAX_HP = 999999000001;

int N;
long long ATK;
Room rooms[MAX_ROOM];

bool isPossible(long long max_hp) {
  long long cur_hp = max_hp;
  long long cur_atk = ATK;

  for(int i = 0; i < N; i++) {
    if(rooms[i].t == 1) {
      long long cnt = rooms[i].h / cur_atk - 1;
      if(rooms[i].h % cur_atk) cnt++;

      cur_hp -= rooms[i].a * cnt;
      if(cur_hp <= 0) return false;
    }
    else {
      cur_atk += rooms[i].a;
      cur_hp += rooms[i].h;
      if(cur_hp > max_hp) {
        cur_hp = max_hp;
      }
    }
  }

  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> ATK;

  for(int i = 0; i < N; i++) {
    cin >> rooms[i].t >> rooms[i].a >> rooms[i].h;
  }

  long long answer = 0;
  long long l = 0, h = MAX_HP * N;

  while(l <= h) {
    long long mid = (l + h) / 2;

    if(isPossible(mid)) {
      answer = mid;
      h = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }

  cout << answer;

  return 0;
}