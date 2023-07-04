#include <iostream>
#include <string>

using namespace std;

const int MAX = 20;
const int ALPHABET = 26;

char board[MAX][MAX];
bool visited[MAX][MAX];
bool checked[ALPHABET];

int R, C;
int maxLength = 0;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void DFS(int x, int y, int cnt) {
    visited[x][y] = true;

    if (cnt > maxLength) 
        maxLength = cnt;

    for (int d = 0; d < 4; d++) {
        int rx = x + dx[d];
        int ry = y + dy[d];

        if (rx < 0 || rx >= R || ry < 0 || ry >= C) continue;

        int i = board[rx][ry] - 'A';

        if (!visited[rx][ry] && !checked[i]) {
            checked[i] = true;
            DFS(rx, ry, cnt + 1);
            visited[rx][ry] = false;
            checked[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> board[i][j];

    checked[board[0][0] - 'A'] = true;
    DFS(0, 0, 1);

    cout << maxLength;

    return 0;
}