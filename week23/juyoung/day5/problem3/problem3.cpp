#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

string str;
stack<int> st;
vector<pair<int, int>> bracket;
vector<string> answer;
bool flag[11];
bool idx[201];

void makeSubset(int cnt) {
  if(cnt == bracket.size()) {
    string temp = "";
    memset(idx, false, sizeof(idx));

    for (int i = 0; i < bracket.size(); i++) {
      if(flag[i]) {
        idx[bracket[i].first] = true;
        idx[bracket[i].second] = true;
      }
    }

    for (int i = 0; i < str.length(); i++) {
      if(!idx[i]) temp += str[i];
    }

    if(temp != str) answer.push_back(temp);
    return;
  }

  flag[cnt] = false;
  makeSubset(cnt + 1);
  flag[cnt] = true;
  makeSubset(cnt + 1);
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> str;
  for (int i = 0; i < str.length(); i++) {
    if(str[i] == '(') {
      st.push(i);
    } else if(str[i] == ')') {
      int idx = st.top();
      st.pop();
      bracket.push_back({idx, i});
    }
  }

  makeSubset(0);

  sort(answer.begin(), answer.end());
  answer.erase(unique(answer.begin(), answer.end()), answer.end());
  
  for (int i = 0; i < answer.size(); i++) {
    cout << answer[i] << "\n";
  }

  return 0;
}