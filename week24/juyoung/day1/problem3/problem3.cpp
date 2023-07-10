#include <iostream>
#include <stack>
using namespace std;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n;
  stack<int> st;
  int answer = 0;

  cin >> n;
  for (int i = 0; i <= n; i++) {
    int x, y;
    if(i!=n) cin >> x >> y;
    else y = 0;

    while(!st.empty() && st.top() >= y) {
      if(st.top()!=y)
        answer++;
      st.pop();
    }
    st.push(y);
  }

  cout << answer << "\n";
  return 0;
}

/*
12
1 1
4 0
5 1
6 0
7 4
8 3
9 2
10 1
11 0
13 1
14 2
15 1
answer = 8

4
1 4
2 3
3 5
4 4
answer = 4

6
1 1
2 2
5 3
6 1
7 3
8 2
answer = 5
*/