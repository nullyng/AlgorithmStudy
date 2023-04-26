#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, a, b, leaf;
vector<vector<int>> map(200001);

void dfs(int here = 0, int prev = -1) {
    if (map[here].size() == 1)
        leaf++;
    for (auto next : map[here]) {
        if (next == prev)
            continue;
        dfs(next, here);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    dfs();

    cout << (leaf + 1) / 2;

    return 0;
}
