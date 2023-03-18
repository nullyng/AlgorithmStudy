#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef pair<int, int> pi;
typedef pair<vector<int>, vector<int>> pv;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, a, b;
    cin >> N;
    vector<pi> list(N);
    unordered_map<int, pv> map;

    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        list[i] = {b, a}; // input 반대로 받았음
    }
    vector<pi> sorted(N);
    sorted = list;
    sort(sorted.begin(), sorted.end());

    for (auto p : sorted) {
        map[p.second].first.push_back(p.first);
    }
    for (auto &entry : map) {
        entry.second.second.push_back(entry.second.first[0]);
        for (int i = 1; i < entry.second.first.size(); i++) {
            entry.second.second.push_back(entry.second.second[i - 1] +
                                          entry.second.first[i]);
        }
    }
    vector<int> weight;
    vector<int> sum;
    for (auto p : sorted) {
        weight.push_back(p.first);
    }
    sum.push_back(weight[0]);
    for (int i = 1; i < weight.size(); i++) {
        sum.push_back(weight[i] + sum[i - 1]);
    }

    for (int i = 0; i < N; i++) {
        int res = 0;
        int idx = upper_bound(weight.begin(), weight.end(), list[i].first - 1) -
                  weight.begin();
        res = idx == 0 ? 0 : sum[idx - 1];
        int myIdx =
            upper_bound(map[list[i].second].first.begin(),
                        map[list[i].second].first.end(), list[i].first - 1) -
            map[list[i].second].first.begin();
        int minus = myIdx == 0 ? 0 : map[list[i].second].second[myIdx - 1];
        cout << res - minus << '\n';
    }

    return 0;
}
