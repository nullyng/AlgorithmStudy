#include <iostream>
#include <vector>
using namespace std;

char girls[5][5];
pair<int, int> combination[7];
bool visited[5][5];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int answer = 0;

void dfs(int y, int x) {
    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(ny<0 || ny>=5 || nx<0 || nx>=5) continue;
        if(visited[ny][nx]) continue;
        visited[ny][nx] = true;
        dfs(ny, nx);
    }
}

void init() {
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            visited[i][j] = true;
        }
    }
    
    for(int i=0; i<7; i++) {
        int x = combination[i].first;
        int y = combination[i].second;
        visited[x][y] = false;
    }
}

bool check() {
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
             if(!visited[i][j]) return false;
        }
    }
    
    return true;
}

void makeComb(int cnt, int idx) {
    if(cnt == 7) {
        int dasom = 0;
        int x, y;
        for(int i=0; i<7; i++) {
            x = combination[i].first;
            y = combination[i].second;
            if(girls[x][y] == 'S') dasom++;
        }
        
        if(dasom >= 4) {
            init();
            dfs(x, y);
            if(check()) answer++; 
        }
        
        return;
    }
    
    for(int i=idx; i<25; i++) {
        combination[cnt] = {i/5, i%5};
        makeComb(cnt+1, i+1);
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            cin >> girls[i][j];
        }
    }
    
    makeComb(0, 0);
    
    cout << answer << "\n";
    return 0;
}