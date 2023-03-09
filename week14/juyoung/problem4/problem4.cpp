#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N;
  int S, T;
  vector<pair<int, int>> lecture;

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> S >> T;
    lecture.push_back({S, T});
  }

  sort(lecture.begin(), lecture.end());

  priority_queue<int> pq;
  pq.push(-lecture[0].second);

  for (int i = 1; i < lecture.size(); i++) {
    if(-pq.top() <= lecture[i].first) pq.pop();
    pq.push(-lecture[i].second);
  }

  cout << pq.size() << "\n";

  return 0;
}