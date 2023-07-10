#include <iostream>

using namespace std;

const int MAX = 1500002;

pair<int, int> info[MAX];
int dp[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> info[i].first >> info[i].second;
    }

    for (int day = N; day >= 1; day--) {
        int time = info[day].first;
        int pay = info[day].second;

        if (day + time > N + 1) {
            dp[day] = dp[day + 1];
        }
        else {
            dp[day] = max(dp[day + 1], pay + dp[day + time]);
        }
    }

    cout << dp[1];

    return 0;
}