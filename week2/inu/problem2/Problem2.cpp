#include <iostream>
#include <vector>

#define INF 999999

using namespace std;

bool visited[50];
int min_cnt = INF;

void isContain(int cnt, string current, string target, vector<string> words) {
	if (cnt >= min_cnt)
		return;

	if (!current.compare(target)) {
		if (cnt < min_cnt) {
			min_cnt = cnt;
			return;
		}
	}

	for (int i = 0; i < (int)words.size(); i++) {
		if (visited[i]) continue;

		int diff = 0;
		string word = words[i];

		for (int idx = 0; idx < (int)current.size(); idx++) {
			if (current[idx] != word[idx]) 
				diff++;
		}

		if (diff == 1 && !visited[i]) {
			visited[i] = true;			
			isContain(cnt + 1, word, target, words);
			visited[i] = false;
		}
	}
}

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	bool flag = true;

	// words에 target이 있는지 검사
	for (string word : words) {
		if (!word.compare(target)) {
			flag = false;
			break;
		}
	}

	if (!flag) {
		isContain(0, begin, target, words);
	}

	if (min_cnt != INF) {
		answer = min_cnt;
	}

	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string begin = "hit", target = "cog";
	vector<string> words = { "hot", "dot", "dog", "lot", "log"};

	cout << solution(begin, target, words);

	return 0;
}