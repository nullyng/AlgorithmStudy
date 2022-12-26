#include <iostream>
#include <queue>
#include <functional> // greater
using namespace std;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N;
  priority_queue<int, vector<int>, greater<int>> pq;
  int answer = 0;

  cin >> N;
  for(int i=0; i<N; i++) {
    int input;
    cin >> input;
    pq.push(input);
  }

  while(pq.size() > 1) {
    int x = pq.top();
    pq.pop();
    int y = pq.top();
    pq.pop();
    answer += x + y;

    pq.push(x+y);
  }

  cout << answer << "\n";
  return 0;
}