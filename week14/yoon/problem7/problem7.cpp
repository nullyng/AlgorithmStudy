#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_map>

using namespace std;

typedef tuple<int, int, char> ti;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unordered_map<char, int> convertDir;
    convertDir['N'] = 0;
    convertDir['E'] = 1;
    convertDir['S'] = 2;
    convertDir['W'] = 3;

    int di[4] = {0, 1, 0, -1};
    int dj[4] = {1, 0, -1, 0};

    int A, B, N, M;
    cin >> A >> B >> N >> M;
    vector<ti> robots(N + 1);
    int map[101][101] = {0};
    for(int i = 1; i <= N; i++){
        int a, b; char c;
        cin >> a >> b >> c;
        robots[i] = {a, b, convertDir[c]};
        map[a][b] = i;
    }

    for(int i = 0; i < M; i++){
        int a, c; char b;
        cin >> a >> b >> c;
        auto [x, y, dir] = robots[a];
        switch(b){
            case 'L':
                robots[a] = {x, y, ((dir - c) % 4 + 4) % 4};
                break;
            case 'R':
                robots[a] = {x, y, (dir + c) % 4};
                break;
            case 'F':
                map[x][y] = 0;
                for(int j = 1; j <= c; j++){
                    int xi = x + di[dir] * j;
                    int xj = y + dj[dir] * j;
                    if(xi < 1 || xj < 1 || xi > A || xj > B){
                        cout << "Robot " << a << " crashes into the wall";
                        return 0;
                    }
                    if(map[xi][xj] != 0) {
                        cout << "Robot " << a << " crashes into robot " << map[xi][xj];
                        return 0;
                    }
                }
                map[x + di[dir] * c][y + dj[dir] * c] = a;
                robots[a] = {x + di[dir] * c, y + dj[dir] * c, dir};
        }
    }
    cout << "OK";
    return 0;
}
