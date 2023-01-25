#include <iostream>
#include <cstring>
#include <string>
#include <set>
#define MAX 95
using namespace std;

struct Trie {
  int cnt;
  Trie* next[MAX];

  Trie() :  cnt(0) {
    memset(next, 0, sizeof(next));
  }

  ~Trie() {
    for (int i = 0; i < MAX; i++) {
      if(next[i]) delete next[i];
    }
  }

  void insert(const char* key) {
    if (*key == '\0') cnt++;
    else {
      int curr = *key - ' ';
      if(next[curr] == NULL)
        next[curr] = new Trie();
      next[curr]->insert(key + 1);
    }
  }

  Trie* find(const char* key) {
    if(*key == '\0')
      return this;
    int curr = *key - ' ';
    if(next[curr] == NULL)
      return NULL;
    return next[curr]->find(key + 1);
  }
};

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  Trie *root = new Trie();
  set<string> list;
  string name;
  double total = 0;
  while (getline(cin, name)) {
    list.insert(name);
    root->insert(name.c_str());
    total++;
  }

  cout << fixed;
  cout.precision(4);
  for (auto iter = list.begin(); iter != list.end(); iter++) {
    cout << *iter << " ";
    cout << (*root->find((*iter).c_str())).cnt * 100 / total << "\n";
  }

  delete root;

  return 0;
}