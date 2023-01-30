#include <iostream>
#include <string>
#include <string.h>
#include <map>

using namespace std;

const int CHARS = 95;
float sum = 0;
map<string, int> trees;
int toNumber(char ch) { return ch - ' '; }
int toChar(int n) { return n + ' '; }

typedef struct TrieNode {
	TrieNode* children[CHARS];
	int cnt;

	TrieNode() : cnt(0) {
		memset(children, 0, sizeof(children));
	}

	~TrieNode() {
		for (int i = 0; i < CHARS; ++i)
			if (children[i])
				delete children[i];
	}

	void insert(const char* key) {
		if (*key == 0) {
			cnt++;
		}
		else {
			int next = toNumber(*key);

			if (children[next] == NULL)
				children[next] = new TrieNode();

			children[next]->insert(key + 1);
		}
	}

	TrieNode* find(const char* key) {
		if (*key == 0)
			return this;

		int next = toNumber(*key);

		if (children[next] == NULL)
			return NULL;

		return children[next]->find(key + 1);
	}
}TrieNode;

void dfs(TrieNode* node, string str) {
	if (node->cnt) {
		sum += node->cnt;
		trees[str] = node->cnt;
	}

	for (int i = 0; i < CHARS; i++) {
		TrieNode* child = node->children[i];
		
		if (child == NULL)
			continue;

		str += toChar(i);
		dfs(child, str);
		str.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	TrieNode* root = new TrieNode();

	while (getline(cin, s)) {
		const char* tree = s.c_str();
		root->insert(tree);
	}

	dfs(root, s);

	cout << fixed;
	cout.precision(4);

	for (auto iter = trees.begin(); iter != trees.end(); iter++) {
		cout << iter->first << ' ';
		cout << (iter->second / sum) * 100 << '\n';
	}

	return 0;
}