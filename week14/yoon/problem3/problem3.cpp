#include <iostream>
#include <vector>
#include <climits>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N, t;
    cin >> N;
    int one = INT_MAX, two = INT_MAX, total = 0, max = INT_MIN;
    vector<int> dice(6);
    for(int i = 0; i < 6; i++) {
        cin >> dice[i];
        total += dice[i];
        if(one > dice[i]) one = dice[i];
        if(max < dice[i]) max = dice[i];
    }
     for(int i = 0; i < 6; i++){
        for(int j = i + 1; j < 6; j++){
            if((i == 0 && j == 5) || (i == 2 && j == 3) || (i == 1 && j == 4)) continue;
            if(dice[i] + dice[j] < two) two = dice[i] + dice[j];
        }
    }
    int thr = min(dice[0], dice[5]) + min(dice[1] + dice[2], min(dice[2] + dice[4], min(dice[1] + dice[3], dice[3] + dice[4])));

    if(N == 1) cout << total - max;
    else if(N == 2) cout << 4 * (thr + two);
    else cout << (5 * (N * N - 4 * N + 4) + 4 * (N - 2)) * one + (8 * (N - 2) + 4) * two + 4 * thr;

    return 0;
}
