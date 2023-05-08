#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int vmax = 100001;

int N, M, a, b;
vector<vector<int>> tree(vmax);
vector<ll> num(vmax);

void dfs(int here = 1) {

    for (auto next : tree[here]) {
        num[next] += num[here];
        dfs(next);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("data.txt", "r", stdin);
#endif

    cin >> N >> M >> a;
    for (int i = 2; i <= N; i++) {
        cin >> a;
        tree[a].push_back(i);
    }

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        num[a] += b;
    }

    dfs();
    for (int i = 1; i <= N; i++)
        cout << num[i] << " ";

    return 0;
}
