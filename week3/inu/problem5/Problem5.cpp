#include <iostream>
#include <vector>
#define INF 999999

using namespace std;

typedef struct pos {
	int x, y;
}pos;

int N, M;
int city[50][50];
int min_dist = INF;
vector<pos> house;
vector<pos> chicken;

void comb(int i, vector<pos> select) {
	if (i >= (int)chicken.size()) {
		if ((int)select.size() == M) {
			int sum = 0;

			for (pos h : house) {
				int min_d = INF;

				for (pos s : select) {
					int d = abs(h.x - s.x) + abs(h.y - s.y);
					min_d = d < min_d ? d : min_d;
				}

				sum += min_d;
			}

			min_dist = sum < min_dist ? sum : min_dist;
		}

		return;
	}

	comb(i + 1, select);

	select.push_back(chicken[i]);
	comb(i + 1, select);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	int info;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> info;

			if (info == 1)
				house.push_back({ i, j });
			else if (info == 2)
				chicken.push_back({ i, j });
		}
	}
	
	comb(0, vector<pos>());

	cout << min_dist;

	return 0;
}