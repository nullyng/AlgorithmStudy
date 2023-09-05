#include <iostream>
#include <queue>

using namespace std;

typedef struct info {
    int x, y;
    int value;
    char op = ' ';
}info;


int N;
int maxValue = -10000;
int minValue = 10000;
int dx[] = { 0, 1 };
int dy[] = { 1, 0 };
char map[5][5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    queue<info> q;
    q.push({ 0, 0, map[0][0] - '0' });

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int value = q.front().value;
        char op = q.front().op;
        q.pop();

        if (x == N - 1 && y == N - 1) {
            maxValue = max(maxValue, value);
            minValue = min(minValue, value);
            continue;
        }

        for (int d = 0; d < 2; d++) {
            int rx = x + dx[d];
            int ry = y + dy[d];
            int rvalue = value;

            if (rx < 0 || rx >= N || ry < 0 || ry >= N) continue;

            int cur = map[rx][ry] - '0';
            // 숫자인 경우
            if (cur >= 0 && cur <= 5) {
                switch (op) {
                case '+':
                    rvalue += cur;
                    break;
                case '-':
                    rvalue -= cur;
                    break;
                case '*':
                    rvalue *= cur;
                    break;
                }
                q.push({ rx, ry, rvalue });
            }
            // 연산자인 경우
            else {
                q.push({ rx, ry, value, map[rx][ry] });
            }
        }
    }

    cout << maxValue << ' ' << minValue;

    return 0;
}