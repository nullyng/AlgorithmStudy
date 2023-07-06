#include <iostream>
#include <map>
using namespace std;

int a, b;
int input;
map<int, bool> m;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> a >> b;
  for (int i = 0; i < a + b; i++) {
    cin >> input;
    if(m[input]) m.erase(input);
    else m[input] = true;
  }
  
  cout << m.size() << "\n";
  return 0;
}