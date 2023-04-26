#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, a;
vector<vector<int>> map(51);

int dfs(int here = 0) {
    if (map[here].size() == 0)
        return 0;

    vector<int> childs;
    for (auto next : map[here]) {
        int child = dfs(next);
        childs.push_back(child);
    }

    sort(childs.begin(), childs.end());
    int res = 0, time = 1;
    for (int i = childs.size() - 1; i >= 0; i--) {
        res = max(res, childs[i] + time++);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> a;

    for (int i = 1; i < N; i++) {
        cin >> a;
        map[a].push_back(i);
    }

    cout << dfs();
    return 0;
}
