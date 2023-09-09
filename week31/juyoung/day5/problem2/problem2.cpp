#include <iostream>
#include <string>
#include <set>
#include <map>
#define pii pair<int, int>
using namespace std;

int N, M;
int P, L;
multiset<pair<int, int>> ms;
map<int, int> m;

bool compare(pii a, pii b) {
  if(a.first == b.first) return a.second < b.second;
  return a.first < b.first;
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> P >> L;
    ms.insert({L, P}); // 난이도, 문제 번호
    m[P] = L;
  }

  cin >> M;
  for (int i = 0; i < M; i++) {
    string command;
    cin >> command;

    if(command == "add") {
      cin >> P >> L;
      ms.insert({L, P});
    } else if(command == "recommend") {
      int x;
      cin >> x;

      if(x == 1) {
        // 가장 어려운 문제의 번호, 여러 개라면 문제 번호가 큰 거
        cout << prev(ms.end())->second << "\n";
      } else {
        // 가장 쉬운 문제의 번호, 여러 개라면 문제 번호가 작은 거
        cout << ms.begin()->second << "\n";
      }
    } else {
      cin >> P;
      ms.erase({m[P], P});
    }
  }

  return 0;
}