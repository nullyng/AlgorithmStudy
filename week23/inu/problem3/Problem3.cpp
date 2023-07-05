#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 1000000;

int N;
pair<int, int> range[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> range[i].first >> range[i].second;

    sort(range, range + N);

    priority_queue<int> pq;
    int e, x, mosq = 0;
    
    for (int i = 0; i < N; i++) {
        pq.push(-range[i].second);

        int prev = -1;
        while (range[i].first >= -pq.top()) {
            prev = -pq.top();
            pq.pop();
        }

        if ((int)pq.size() > mosq) {
            e = range[i].first;
            x = -pq.top();
            mosq = (int)pq.size();
        }
        else if ((int)pq.size() == mosq && range[i].first == prev) {
            x = -pq.top();
        }
    }

    cout << mosq << '\n';
    cout << e << ' ' << x;

    return 0;
}