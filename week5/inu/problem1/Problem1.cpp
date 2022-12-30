#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct pos {
    int A, B;
}pos;

bool compare(pos p1, pos p2) {
    return p1.A < p2.A;
}

int N;
vector<pos> line;
vector<int> LIS;

int LowerBound(int k) {
    int len = (int)LIS.size();
    int lo = -1, hi = len;

    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;

        if (!(LIS[mid] >= k)) lo = mid;
        else hi = mid;
    }

    return hi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        line.push_back({ A, B });
    }

    sort(line.begin(), line.end(), compare);

    for (int i = 0; i < N; i++) {
        int len = (int)LIS.size();

        if (len == 0) {
            LIS.push_back(line[i].B);
            continue;
        }

        if (line[i].B > LIS[len - 1]) {
            LIS.push_back(line[i].B);
        }
        else {
            int p = LowerBound(line[i].B);
            LIS[p] = line[i].B;
        }
    }

    cout << N - (int)LIS.size();

    return 0;
}