#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    vector<int> nums(N);
    for (int i = 0; i < N; i++)
        cin >> nums[i];

    int res = INT_MAX;
    int left = 0, right = 999999999; // 키차이 최대 최소
    while (left <= right) {
        int mid = (left + right) / 2;
        int k = 1, past = 0, idx = 0, sum = 0;
        while (idx < N) {
            if (nums[idx] - nums[past] > mid) {
                k++;
                sum += nums[idx - 1] - nums[past];
                past = idx;
            } else {
                idx++;
            }
        }
        sum += nums[idx - 1] - nums[past];
        if (k < K) {
            right = mid - 1;
        } else if (k > K) {
            left = mid + 1;
        } else {
            right = mid - 1;
            res = min(res, sum);
        }
    }

    cout << res;

    return 0;
}
