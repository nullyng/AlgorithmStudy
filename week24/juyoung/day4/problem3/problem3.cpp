#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string S, T;
int answer;

void check(string temp) {
  if(temp == S) {
      answer = 1;
      return;
  }
  
  int end = temp.length()-1;
  if(temp[end] == 'A') check(temp.substr(0, end));
  if(temp[0] == 'B') {
      reverse(temp.begin(), temp.end());
      check(temp.substr(0, end));
  }
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  
  cin >> S >> T;
  
  check(T);
  cout << answer << "\n";

  return 0;
}