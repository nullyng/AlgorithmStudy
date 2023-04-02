#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <deque>
using namespace std;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;

  while(T--) {
    string p;
    int n;
    cin >> p >> n;

    string arr;
    cin >> arr;

    istringstream ss(arr.substr(1, arr.length()-2));
    string buffer;
    deque<int> num;
    while (getline(ss, buffer, ',')) {
      num.push_back(stoi(buffer));
    }

    int rcnt, fdel, edel;
    rcnt = fdel = edel = 0;

    for (int i = 0; i < p.length(); i++) {
      if(p[i] == 'R') rcnt++;
      else if(p[i] == 'D') {
        if(rcnt%2==0) fdel++;
        else edel++;
      }
    }

    if(fdel+edel > n) cout << "error\n";
    else {
      for (int i = 0; i < fdel; i++) num.pop_front();
      for (int i = 0; i < edel; i++) num.pop_back();

      if (rcnt % 2 == 1) reverse(num.begin(), num.end());

      cout << "[";
      for (int i = 0; i < num.size(); i++) {
        if(i == num.size()-1) cout << num[i];
        else cout << num[i] << ",";
      }
      cout << "]\n";
    }
  }

  return 0;
}