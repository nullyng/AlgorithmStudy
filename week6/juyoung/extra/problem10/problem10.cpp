#include <string>
#include <vector>

using namespace std;

int root[200];
bool visited[200];

int Find(int x) {
    if(x == root[x]) return x;
    return root[x] = Find(root[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if(x!=y) root[y] = x;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0; i<n; i++) root[i] = i;
    
    for(int i=0; i<(int)computers.size(); i++) {
        for(int j=0; j<(int)computers[i].size(); j++) {
            if(i==j) continue;
            if(computers[i][j]) Union(i, j);
        }
    }
    
    for(int i=0; i<n; i++) {
        int r = Find(i);
        if(visited[r]) continue;
        visited[r] = true;
        answer++;
    }
    
    return answer;
}