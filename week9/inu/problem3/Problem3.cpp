#include <iostream>
#include <string.h>
#include <unordered_map>

using namespace std;

const int ALPHABETS = 26;
int toNumber(char ch) { return ch - 'a'; }
unordered_map<string, int> nicknames;

typedef struct TrieNode {
	TrieNode* children[ALPHABETS];
	bool terminal;

	TrieNode() : terminal(false) {
		memset(children, 0, sizeof(children));
	}

	~TrieNode() {
		for (int i = 0; i < ALPHABETS; i++)
			if (children[i])
				delete children[i];
	}

	void insert(const char* key, string s = "", bool nickname = false) {
		if (*key == 0) {
			terminal = true;

			if (!nickname) {
				cout << s << '\n';
				nickname = true;
			}

			return;
		}
		else {
			s += *key;

			int next = toNumber(*key);

			if (!children[next]) {
				children[next] = new TrieNode();

				if (!nickname) {
					cout << s << '\n';
					nickname = true;
				}
			}				

			children[next]->insert(key + 1, s, nickname);
		}
	}
}TrieNode;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	string s;
	TrieNode* trie = new TrieNode();

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> s;
		
		if (!nicknames[s]) {
			trie->insert(s.c_str());
		}
		else {
			cout << s << nicknames[s] + 1 << '\n';
		}

		nicknames[s]++;
	}

	return 0;
}