#include <algorithm>
#include <cmath>
#include <iostream>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;

typedef tuple<int, int, int> ti;

int fin(vector<int> &parent, int a) {
    if (a == parent[a])
        return a;
    return parent[a] = fin(parent, parent[a]);
}

void merge(vector<int> &parent, int a, int b) {
    int pa = fin(parent, a);
    int pb = fin(parent, b);
    parent[pa] = pb;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N, a, b, c;
    cin >> T;
    while (T--) {
        cin >> N;
        vector<ti> list;
        vector<int> parent(N);

        for (int i = 0; i < N; i++) {
            parent[i] = i;
            cin >> a >> b >> c;
            list.push_back({a, b, c});
        }

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                auto [a, b, c] = list[i];
                auto [x, y, r] = list[j];
                if ((x - a) * (x - a) + (y - b) * (y - b) <=
                    (r + c) * (r + c)) {
                    merge(parent, i, j);
                }
            }
        }
        unordered_set<int> res;
        for (int i = 0; i < N; i++) {
            res.insert(fin(parent, i));
        }
        cout << res.size() << '\n';
    }

    return 0;
}
