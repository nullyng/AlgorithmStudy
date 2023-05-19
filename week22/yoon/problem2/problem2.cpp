#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
int K, N;
ll res;
vector<ll> tree((1 << 21) + 1, 0);
vector<ll> rev((1 << 21) + 1, 0);

void dfs(int here = 1, ll weight = rev[1]) {
    if (here > N)
        return;
    if (here == 1) {
        dfs(here * 2);
        dfs(here * 2 + 1);
        return;
    }
    res += tree[here];
    if (weight == 0) {
        dfs(here * 2, weight);
        dfs(here * 2 + 1, weight);
        return;
    }

    res += weight - rev[here];
    weight = rev[here] - tree[here];

    dfs(here * 2, weight);
    dfs(here * 2 + 1, weight);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("data.txt", "r", stdin);
#endif

    cin >> K;
    N = (1 << (K + 1)) - 1;
    for (int i = 2; i <= N; i++) {
        cin >> tree[i];
        rev[i] = tree[i];
    }

    for (int i = N / 2; i >= 1; i--) {
        rev[i] += max(rev[i * 2], rev[i * 2 + 1]);
    }

    dfs();
    cout << res;
    return 0;
}
