#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, a, b;
    cin >> N >> M;
    vector<pi> list(N);
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        list[i] = {b, a}; // 가격, 무게
    }

    vector<ll> sumList(N);

    sort(list.begin(), list.end());

    sumList[0] = list[0].second;

    ll sum = 0, rest = list[0].second;
    for (int i = 1; i < N; i++) {
        if (list[i].first > list[i - 1].first) {
            sum += rest;
            sumList[i] = sum + list[i].second;
            rest = list[i].second;
        } else {
            sumList[i] = sum + list[i].second;
            rest += list[i].second;
        }
    }

    int idx = lower_bound(sumList.begin(), sumList.end(), M) - sumList.begin();
    ll otherPrice = -1;
    if (idx != 0 && list[idx].first != list[idx - 1].first) {
        ll price = list[idx - 1].first;
        ll otherRes = sumList[idx - 1];
        for (int i = idx - 2; i >= 0; i--) {
            if (list[idx - 1].first != list[i].first) {
                break;
            }
            price += list[i].first;
            otherRes += list[i].second;
            if (otherRes >= M) {
                otherPrice = price;
                break;
            }
        }
    }

    ll res = -1;
    if (idx != list.size()) {
        res = list[idx].first;
    }
    if (otherPrice != -1) {
        if (res == -1)
            res = otherPrice;
        else
            res = min(res, otherPrice);
    }

    cout << res;

    return 0;
}
