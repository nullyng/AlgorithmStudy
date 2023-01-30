#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  map<string, int> tree;
  string name;
  double total = 0;

  while (getline(cin, name)) {
    tree[name]++;
    total++;
  }

  cout << fixed;
  cout.precision(4);
  for (auto iter = tree.begin(); iter != tree.end(); iter++) {
    cout << iter->first << " ";
    cout << iter->second*100 / total << "\n";
  }

  return 0;
}