#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct Trie {
  int cnt;
  Trie *next[26];

  Trie() : cnt(0) {
    memset(next, 0, sizeof(next));
  }

  ~Trie() {
    for(int i=0; i<26; i++) delete next[i];
  }

  string insert(char *key, string result) {
    if(*key == '\0') {
      if(++cnt == 1) return result;
      return result + to_string(cnt);
    }
    
    int curr = *key - 'a';
    result += *key;
    if(next[curr] == NULL) {
      next[curr] = new Trie();
      next[curr]->insert(key+1, result);
      return result; 
    }

    return next[curr]->insert(key+1, result);
  }
};

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N;
  Trie *root = new Trie();
  char nickname[11];

  cin >> N;
  for(int i=0; i<N; i++) {
    cin >> nickname;
    cout << root->insert(nickname, "") << "\n";
  }

  delete root;

  return 0;
}