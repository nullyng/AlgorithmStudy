#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, H;

int Upper_bound(vector<int> v, int num) {
	int lo = -1;
	int hi = (int)v.size();

	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (!(v[mid] > num)) lo = mid;
		else hi = mid;
	}

	return hi;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> H;

	int last = (N / 2) - 1;
	vector<int> cnt1, cnt2;
	vector<int> top, bottom;

	cnt1.assign(H + 1, 0);
	cnt2.assign(H + 1, 0);

	for (int i = 0; i < N; i++) {
		int h;
		cin >> h;

		if (i % 2) top.push_back(h);
		else bottom.push_back(h);
	}

	sort(bottom.begin(), bottom.end());
	sort(top.begin(), top.end());

	for (int i = last; i >= 0; i--) {
		cnt1[top[i]]++;
		cnt2[bottom[i]]++;
	}

	for (int i = H - 1; i > 0; i--) {
		cnt1[i] += cnt1[i + 1];
		cnt2[i] += cnt2[i + 1];
	}

	for (int i = 1; i <= H; i++) {
		cnt2[i] += cnt1[(H - i) + 1];
	}

	sort(cnt2.begin(), cnt2.end());

	cout << cnt2[1] << ' ' << Upper_bound(cnt2, cnt2[1]) - 1;

	return 0;
}