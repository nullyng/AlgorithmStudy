#include <iostream>

using namespace std;

const int MAX = 1 << 21;

int k, n;
int sum = 0;
int tree[MAX];
int acc[MAX];

void travel(int cur, int w) {
	if (acc[cur] + w < acc[1]) 
		tree[cur] += acc[1] - (acc[cur] + w);
	
	sum += tree[cur];

	if (cur < n / 2) {
		travel(cur * 2, tree[cur] + w);
		travel(cur * 2 + 1, tree[cur] + w);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> k;
	n = 1 << (k + 1);

	for (int i = 2; i < n; i++)
		cin >> tree[i];
	
	for (int i = n / 2; i < n; i++)
		acc[i] = tree[i];

	for (int i = n / 2 - 1; i > 0; i--)
		acc[i] = tree[i] + max(acc[i * 2], acc[i * 2 + 1]);

	travel(1, 0);

	cout << sum;

	return 0;
}