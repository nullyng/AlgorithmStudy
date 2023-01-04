#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, pair<string, int>> m;

string Find(string str) {
  if(m[str].first == str) return str;
  return m[str].first = Find(m[str].first);
}

void Union(string A, string B) {
  A = Find(A);
  B = Find(B);

  if(A!=B) {
    if(m[A].second < m[B].second) {
      m[A].first = m[B].first;
      m[B].second += m[A].second;
    }
    else {
      m[B].first = m[A].first;
      m[A].second += m[B].second;
    }
  }
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int T, F;

  cin >> T;
  while(T--) {
    m.erase(m.begin(), m.end());

    cin >> F;
    for(int i=0; i<F; i++) {
      string A, B;
      cin >> A >> B;
      
      if(m.find(A) == m.end()) m[A] = {A, 1};
      if(m.find(B) == m.end()) m[B] = {B, 1};
      Union(A, B);

      cout << m[Find(A)].second << "\n";
    }
  }

  return 0;
}