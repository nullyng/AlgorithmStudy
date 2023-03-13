// 현재는 실패한 코드
#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int res = INT_MAX;

void simul(vector<bool> &arr, int N, int idx, int cnt) {
    if (idx == N - 1) {
        bool flag = true;
        for (int i = 0; i < N; i++) {
            if (arr[i] == true) {
                flag = false;
                break;
            }
        }

        if (flag) {
            res = min(res, cnt);
        }

        arr[idx] = !arr[idx];
        arr[idx - 1] = !arr[idx - 1];

        flag = true;
        for (int i = 0; i < N; i++) {
            if (arr[i] == true) {
                flag = false;
                break;
            }
        }

        if (flag) {
            res = min(res, cnt + 1);
        }
        arr[idx] = !arr[idx];
        arr[idx - 1] = !arr[idx - 1];

        return;
    }

    if (arr[idx - 1] == 0) {
        simul(arr, N, idx + 1, cnt);
    }

    arr[idx] = !arr[idx];
    arr[idx - 1] = !arr[idx - 1];
    arr[idx + 1] = !arr[idx + 1];

    if (arr[idx - 1] == 0) {
        simul(arr, N, idx + 1, cnt + 1);
    }

    arr[idx] = !arr[idx];
    arr[idx - 1] = !arr[idx - 1];
    arr[idx + 1] = !arr[idx + 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    vector<bool> arr(N + 1);
    string a, b;
    cin >> N >> a >> b;
    for (int i = 0; i < N; i++) {
        arr[i] = a[i] ^ b[i];
    }

    simul(arr, N, 1, 0);

    arr[0] = !arr[0];
    arr[1] = !arr[1];

    simul(arr, N, 1, 1);

    cout << (res == INT_MAX ? -1 : res);

    return 0;
}
