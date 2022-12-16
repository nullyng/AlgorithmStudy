#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int binarySearch(int num) {
	int result = 0;
	int lo = -1;
	int hi = (int)v.size();

	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;

		if (num < v[mid]) hi = mid;
		else lo = mid;
	}

	if (v[lo] == num)
		result = 1;

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	int num;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> num;
		cout << binarySearch(num) << '\n';
	}

	return 0;
}