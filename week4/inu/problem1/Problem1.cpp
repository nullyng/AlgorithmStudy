#include <iostream>

using namespace std;

int N;
char image[64][64];
string tree = "";

void divide(int x1, int x2, int y1, int y2) {
	bool flag = true;
	int i = x1;
	int j = y1;
	char c = image[x1][y1];

	while (1) {
		if (c != image[i][j]) {
			flag = false;
			break;
		}

		if (++j > y2) {
			j = y1;
			if (++i > x2) break;
		}
	}

	if (flag) {
		tree += image[x1][y1];
	}
	else {
		tree += '(';
		divide(x1, (x1 + x2) / 2, y1, (y1 + y2) / 2);
		divide(x1, (x1 + x2) / 2, (y1 + y2) / 2 + 1, y2);
		divide((x1 + x2) / 2 + 1, x2, y1, (y1 + y2) / 2);
		divide((x1 + x2) / 2 + 1, x2, (y1 + y2) / 2 + 1, y2);
		tree += ')';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> image[i][j];

	divide(0, N - 1, 0, N - 1);

	cout << tree;

	return 0;
}