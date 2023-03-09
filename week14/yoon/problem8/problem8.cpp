#include <iostream>

using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, L, R;
    cin >> N >> L >> R;
    int map[51][51] = {0};

    while(1){
        bool visited[51][51] = {false};

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(visited[i][j]) continue;
                dfs(map, visited, i, j);
            }
        }



    }


    return 0;
}
