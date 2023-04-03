#include <iostream>
#include <string>
using namespace std;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int T;
  string str;

  cin >> T;
  while(T--) {
    cin >> str;

    int left = 0;
    int right = str.length() - 1;
    int pseudo = 0;

    while (left < right) {
      if(str[left] != str[right]) {
        if(pseudo > 0) {
          pseudo++;
          break;
        }

        if(str[left+1] == str[right]) {
          int t_left = left + 1;
          int t_right = right;
          bool flag = false;

          while(t_left < t_right) {
            if(str[t_left] != str[t_right]) {
              flag = true;
              break;
            }

            t_left++; t_right--;
          }

          if(flag) right--;
          else left++;
        }
        else if (str[left] == str[right - 1]) {
          int t_left = left;
          int t_right = right - 1;
          bool flag = false;

          while(t_left < t_right) {
            if(str[t_left] != str[t_right]) {
              flag = true;
              break;
            }

            t_left++; t_right--;
          }

          if(flag) left++;
          else right--;
        }
        else {
          pseudo = 2;
          break;
        }
        pseudo++;
      }

      left++;
      right--;
    }

    if(pseudo == 0) cout << "0\n";
    else if(pseudo == 1) cout << "1\n";
    else cout << "2\n";
  }

  return 0;
}