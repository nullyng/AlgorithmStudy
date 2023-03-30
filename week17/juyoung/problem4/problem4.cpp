#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  string PPAP;
  cin >> PPAP;

  stack<char> st;

  for (int i = 0; i < PPAP.length(); i++) {
    if(PPAP.substr(i, 2) == "AP") {
      if(st.size() >= 2) {
        int top1 = st.top();
        st.pop();
        int top2 = st.top();
        st.pop();

        if(top1 == 'P' && top2 =='P') {
          st.push('P');
          i++;
        } else {
          st.push(top2);
          st.push(top1);
        }
      } else {
        cout << "NP\n";
        return 0;
      }
    }
    else {
      st.push(PPAP[i]);
    }
  }

  if(st.size() == 1 && st.top() == 'P') cout << "PPAP\n";
  else cout << "NP\n";

  return 0;
}