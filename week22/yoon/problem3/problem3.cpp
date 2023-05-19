#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

int dfs(vector<vector<pi>> &tree, int w, int here = 1, int prev = 0) {
    int res = 0;
    for (auto n : tree[here]) {
        auto [next, weight] = n;
        if (next == prev)
            continue;

        res += dfs(tree, weight, next, here);
    }
    if (here == 1)
        return res;
    return res == 0 ? w : min(res, w);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("data.txt", "r", stdin);
#endif

    int T, N, M, a, b, c;
    cin >> T;
    while (T--) {
        cin >> N >> M;
        vector<vector<pi>> tree(N + 1);
        for (int i = 0; i < M; i++) {
            cin >> a >> b >> c;
            tree[a].push_back({b, c});
            tree[b].push_back({a, c});
        }

        cout << dfs(tree, 0) << '\n';
    }

    return 0;
}
