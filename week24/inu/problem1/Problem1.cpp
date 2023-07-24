#include <iostream>
#include <stack>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  int answer = 0;
  stack<int> height;

  cin >> n;

  for(int i = 0; i < n; i++) {
    int x, y;
    
    cin >> x >> y;
    
    while(!height.empty() && height.top() >= y) {
      if(height.top() != y) answer++;
      height.pop();
    }

    height.push(y);
  }

  while(!height.empty()) {
    if(height.top() != 0) answer++;
    height.pop();
  }

  cout << answer;

  return 0;
}