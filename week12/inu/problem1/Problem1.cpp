#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

struct compare {
	bool operator()(pii a1, pii a2) {
		if (a1.first == a2.first)
			return a1.second < a2.second;
		return a1.first < a2.first;
	}
};

int N;
int score[1001];

int Find(int d) {
	int idx = d;

	while (score[idx]) {
		idx--;
	}

	if (idx == 0) idx = -1;

	return idx;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	int max_d = 0;
	priority_queue<pii, vector<pii>, compare> todos;

	for (int i = 0; i < N; i++) {
		int d, w;
		cin >> d >> w;
		todos.push({ w, d });
		max_d = max(max_d, d);
	}

	while (!todos.empty()) {
		pii todo = todos.top();
		todos.pop();

		int d = todo.second;
		int w = todo.first;

		d = Find(d);

		if (d != -1) {
			score[d] = w;
		}
	}

	int sum = 0;

	for (int i = 1; i <= max_d; i++)
		if (score[i]) 
			sum += score[i];

	cout << sum;

	return 0;
}

/*
8
4 60
4 50
4 40
1 20
2 50
3 30
4 10
6 5

6
3 5
3 5
3 5
2 4
2 4
1 4

1 2 3 4 5
2  2  3  3  3  
*/