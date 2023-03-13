#include <iostream>
#include <vector>

using namespace std;

int d;
long long x, y;
string numbers;

int getNumber(vector<long long> center, long long cx, long long cy) {
    int number = 0;
    long long dx = center[0], dy = center[1];

    if (dx > cx && dy > cy) number = 1;
    else if (dx < cx && dy > cy) number = 2;
    else if (dx < cx && dy < cy) number = 3;
    else number = 4;

    return number;
}

vector<long long> getCenter(vector<long long> center, long long len, int idx) {
    if (idx >= d) {
        return center;
    }

    int number = numbers[idx] - '0';

    switch (number) {
    case 1:
        center[0] += len;
        center[1] += len;
        break;
    case 2:
        center[0] -= len;
        center[1] += len;
        break;
    case 3:
        center[0] -= len;
        center[1] -= len;
        break;
    case 4:
        center[0] += len;
        center[1] -= len;
        break;
    }

    return getCenter(center, len / 2, idx + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> d >> numbers;
    cin >> x >> y;

    vector<int> answer;
    int iter = d;
    long long len = 1;

    while (iter) {
        len *= 2;
        iter--;
    }

    vector<long long> center(2);
    center[0] = 0;
    center[1] = 0;

    center = getCenter(center, len / 2, 0);
    center[0] += (x * 2);
    center[1] += (y * 2);

    if (center[0] < -len || center[0] > len || center[1] < -len || center[1] > len) {
        answer.push_back(-1);
    }
    else {
        int idx = 0;
        long long cx = 0, cy = 0;
        len /= 2;

        while (idx < d) {
            int number = getNumber(center, cx, cy);

            switch (number) {
            case 1:
                cx += len;
                cy += len;
                break;
            case 2:
                cx -= len;
                cy += len;
                break;
            case 3:
                cx -= len;
                cy -= len;
                break;
            case 4:
                cx += len;
                cy -= len;
                break;
            }

            answer.push_back(number);
            idx++;
            len /= 2;
        }
    }

    for (int n : answer)
        cout << n;

    return 0;
}