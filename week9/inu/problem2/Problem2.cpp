#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

const int NUMBER = 10;
int toNumber(char ch) { return ch - '0'; }

typedef struct TrieNode {
	TrieNode* children[NUMBER];
	bool terminal;

	TrieNode() : terminal(false) {
		memset(children, 0, sizeof(children));
	}

	~TrieNode() {
		for (int i = 0; i < NUMBER; i++)
			if (children[i])
				delete children[i];
	}

	void insert(const char* key) {
		if (*key == 0) {
			terminal = true;
		}
		else {
			int next = toNumber(*key);

			if (!children[next])
				children[next] = new TrieNode();

			children[next]->insert(key + 1);
		}
	}

	TrieNode* find(const char* key) {
		if (*key == 0)
			return this;

		int next = toNumber(*key);

		if (!children[next])
			return NULL;

		return children[next]->find(key + 1);
	}

	bool isCostant(const char* key) {
		if (*key && terminal)
			return false;

		if (*key == 0)
			return true;

		int next = toNumber(*key);

		if (!children[next])
			return NULL;

		return children[next]->isCostant(key + 1);
	}
}TrieNode;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T, N;

	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N;
		
		TrieNode* trie = new TrieNode();
		vector<string> phones(N, "");
		string answer = "YES";

		for (int i = 0; i < N; i++) {
			cin >> phones[i];
			trie->insert(phones[i].c_str());
		}

		for (string phone : phones) {
			const char* c = phone.c_str();
			if (!trie->isCostant(c)) {
				answer = "NO";
				break;
			}
		}

		cout << answer << '\n';
	}

	return 0;
}