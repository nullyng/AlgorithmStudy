#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<ll> nums(1000001, 1);
    vector<ll> sum(1000001, 0);
    for (int i = 2; i <= 1000000; i++) {
        for (int j = i; j <= 1000000; j += i) {
            nums[j] += i;
        }
    }
    sum[1] = 1;
    for (int i = 2; i <= 1000000; i++) {
        sum[i] = sum[i - 1] + nums[i];
    }

    int T, N;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        cout << sum[N] << '\n';
    }

    return 0;
}
