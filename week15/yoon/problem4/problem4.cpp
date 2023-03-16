#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N, M, res = 0;
    cin >> N >> M;
    vector<ll> num(N + 1);
    vector<ll> sum(N + 1);
    unordered_map<ll, ll> map;
    for (int i = 1; i <= N; i++) {
        cin >> num[i];
        sum[i] = num[i] + sum[i - 1];
        sum[i] %= M;
        res += map[sum[i]] + (sum[i] == 0 ? 1 : 0);
        map[sum[i]]++;
    }

    cout << res;

    return 0;
}
