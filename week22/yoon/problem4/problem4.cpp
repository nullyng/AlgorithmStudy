#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int vmax = 10001;

typedef pair<int, int> pi;

int N, a, b;
vector<vector<int>> tree(vmax);
int num[vmax];

pi dfs(int here = 1, int prev = 0) {
    pi res = {0, num[here]};
    auto &[ra, rb] = res;

    for (auto next : tree[here]) {
        if (next == prev)
            continue;
        auto [a, b] = dfs(next, here);

        ra += max(a, b);
        rb += a;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("data.txt", "r", stdin);
#endif

    int res = 0;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> num[i];
        res += num[i];
    }

    for (int i = 1; i < N; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    auto [p, q] = dfs();
    cout << max(p, q);

    return 0;
}
