#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string s1, s2;
  int max_len = 0;
  int len1 = 0, len2 = 0;

  cin >> s1 >> s2;

  len1 = (int)s1.length();
  len2 = (int)s2.length();

  for(int i = 0; i < len1; i++) {
    for(int j = 0; j < len2; j++) {
      if(s1[i] != s2[j]) continue;

      int _i = i + 1;
      int _j = j + 1;
      int len = 1;

      while(_i < len1 && _j < len2) {
        if(s1[_i] != s2[_j]) break;
        _i++;
        _j++;
        len++;
      }

      if(len > max_len) max_len = len;
    }
  }

  cout << max_len;

  return 0;
}