#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 200000

using namespace std;

typedef struct ball {
	int idx, c, s;
}ball;

int sum[MAX + 1];
int C[MAX + 1];
int S[2001];
vector<ball> balls;

bool compare(ball b1, ball b2) {
	if (b1.s == b2.s)
		return b1.c < b2.c;
	return b1.s < b2.s;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		int c, s;
		cin >> c >> s;
		balls.push_back({ i, c, s });
	}

	sort(balls.begin(), balls.end(), compare);

	int prefixSum = 0;
	
	for (int i = 0; i < N; i++) {
		int idx = balls[i].idx;
		int c = balls[i].c;
		int s = balls[i].s;

		C[c] += s;
		S[s] += s;
		prefixSum += s;

		sum[idx] = prefixSum - C[c] - S[s] + s;

		if (i > 0 && (balls[i - 1].c == c) && (balls[i - 1].s == s))
			sum[idx] = sum[balls[i - 1].idx];
	}

	for (int i = 0; i < N; i++)
		cout << sum[i] << '\n';

	return 0;
}