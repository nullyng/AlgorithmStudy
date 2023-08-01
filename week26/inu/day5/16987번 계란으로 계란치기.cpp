#include <iostream>

using namespace std;

typedef struct Egg {
	int s;
	int w;
}Egg;

const int MAX = 8;

int N;
int answer = 0;
bool isCrashed[MAX];
Egg eggs[MAX];

void hitEggs(int cur) {
	if (cur >= N) {
		int cnt = 0;

		for (int i = 0; i < N; i++)
			if (isCrashed[i]) cnt++;

		answer = max(answer, cnt);

		return;
	}

	if (isCrashed[cur]) {
		hitEggs(cur + 1);
	}
	else {
		for (int i = 0; i < N; i++) {
			if (i == cur) continue;

			if (!isCrashed[i]) {
				eggs[cur].s -= eggs[i].w;
				eggs[i].s -= eggs[cur].w;

				if (eggs[cur].s <= 0) {
					isCrashed[cur] = true;
				}
				if (eggs[i].s <= 0) {
					isCrashed[i] = true;
				}

				hitEggs(cur + 1);

				eggs[cur].s += eggs[i].w;
				eggs[i].s += eggs[cur].w;
				isCrashed[cur] = false;
				isCrashed[i] = false;
			}
			else hitEggs(cur + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> eggs[i].s >> eggs[i].w;
	}

	hitEggs(0);

	cout << answer;

	return 0;
}