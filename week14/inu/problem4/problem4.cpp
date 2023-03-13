#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N;
  vector<pair<int, int>> inst;
  priority_queue<int> q;

  cin >> N;

  for(int i = 0; i < N; i++) {
    int s, t;
    cin >> s >> t;
    inst.push_back({ s, t });
  }

  sort(inst.begin(), inst.end());

  q.push(-inst[0].second);

  for(int i = 1; i < N; i++) {
    int preEnd = -q.top();
    int nextStart = inst[i].first;

    q.push(-inst[i].second);

    if(nextStart >= preEnd) q.pop();
  }

  cout << q.size();

  return 0;
}