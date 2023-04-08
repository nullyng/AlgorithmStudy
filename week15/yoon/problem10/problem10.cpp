#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> list(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> list[i];
        sum += list[i];
    }
    if (sum % 3 != 0) {
        cout << "NO";
        return 0;
    }

    vector<int> rest(3, 0);
    vector<int> storage(3, 0);

    for (int i = 0; i < N; i++) {
        if (list[i] % 3 != 0) {
            rest[list[i] % 3]++;
        }
        int deleted = list[i] - (list[i] % 3); // 3의 배수
        storage[1] += deleted; // 1 비상식량 // 2가 남았을 때 여기꺼 쓰면 됨
        storage[2] += (deleted - (deleted % 6)) / 2;
    }

    int diff = min(rest[1], rest[2]);
    rest[1] -= diff;
    rest[2] -= diff;

    if (rest[1] > 0) {
        if (storage[2] < rest[1]) {
            cout << "NO";
            return 0;
        }
    } else if (rest[2] > 0) {
        if (storage[1] < rest[2]) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}
