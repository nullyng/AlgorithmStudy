#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, t;
    cin >> N >> M;
    vector<int> pos;
    vector<int> neg;
    for (int i = 0; i < N; i++) {
        cin >> t;
        if (t > 0)
            pos.push_back(t);
        else
            neg.push_back(-1 * t);
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    int res = 0, maxx = 0;
    while (!pos.empty()) {
        maxx = max(maxx, pos.back());
        res += pos.back();
        for (int i = 0; i < M; i++) {
            if (!pos.empty())
                pos.pop_back();
        }
    }
    while (!neg.empty()) {
        maxx = max(maxx, neg.back());
        res += neg.back();
        for (int i = 0; i < M; i++) {
            if (!neg.empty())
                neg.pop_back();
        }
    }
    res *= 2;
    res -= maxx;
    cout << res;

    return 0;
}
