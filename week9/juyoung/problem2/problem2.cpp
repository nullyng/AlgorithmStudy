#include <iostream>
#include <cstring>
using namespace std;

struct Trie {
  bool finish;
  Trie *next[10];

  Trie() : finish(false) {
    memset(next, 0, sizeof(next));
  }

  ~Trie() {
    for (int i = 0; i < 10; i++) {
      if(next[i]) delete next[i];
    }
  }

  void insert(char *key) {
    if(*key == '\0') finish = true;
    else {
      int curr = *key - '0';
      if(next[curr] == NULL)
        next[curr] = new Trie();
      next[curr]->insert(key + 1);
    }
  }

  bool find(char *key) {
    if(*key == '\0') return true;
    if(finish) return false;

    int curr = *key - '0';
    return next[curr]->find(key + 1);
  }
};

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while(t--) {
    int n;
    Trie *root = new Trie();
    char number[10001][11];
    bool answer = true;

    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> number[i];
      root->insert(number[i]);
    }

    for (int i = 0; i < n; i++) {
      if (!root->find(number[i])) {
        answer = false;
        break;
      }
    }

    if (answer) cout << "YES\n";
    else cout << "NO\n";

    delete root;
  }

  return 0;
}