#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

int binSearch(vector<pi> list, int target, int left, int right) {
    int minn = list.back().first;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (list[mid].second < target) {
            left = mid + 1;
        } else if (list[mid].second >= target) {
            minn = min(minn, list[mid].first);
            right = mid - 1;
        }
    }

    return minn;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, a, b;
    cin >> N >> M;
    vector<pi> list(N);
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        list[i] = {b, a};
    }
    sort(list.begin(), list.end());

    int sum = 0;
    int stack = list[0].second;
    for (int i = 1; i < list.size(); i++) {
        if (list[i].first > list[i - 1].first) {
            sum += stack;
            stack = list[i].second;
            list[i].second += sum;
        } else {
            stack += list[i].second;
            list[i].second += sum;
        }
    }
    if (M > list.back().second)
        cout << -1;
    else {
        cout << binSearch(list, M, 0, N - 1);
    }
    return 0;
}
