#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N, S;
vector<int> seq;
map<int, int, greater<int>> info;

void update(int n, int from, int to) {
  for(auto el : info) {
    int _n = el.first;
    int _i = el.second;

    if(_n != n && _i >= from && _i <= to)
      info[_n]++;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  for(int i = 0; i < N; i++) {
    int n;
    cin >> n;
    seq.push_back(n);
    info[n] = i;
  }

  cin >> S;

  int cur = 0;

  for(auto el : info) {
    int n = el.first;
    int i = el.second;
    int move = i - cur;

    if(move <= 0) {
      cur++;
      continue;
    }

    if(S >= move) {
      // 인덱스 업데이트
      update(n, cur, i - 1);
      info[n] = cur;
      // 그 다음 위치, 남은 횟수 업데이트
      cur++;
      S -= move;
    }

    if(S <= 0 || cur >= N - 1) break;
  }

  for(auto el : info) {
    int n = el.first;
    int i = el.second;
    seq[i] = n;
  }

  for(int n : seq)
    cout << n << ' ';

  return 0;
}