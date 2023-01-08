#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int root[101];
vector<pair<int, int>> adjList[101];
bool visited[101];
int answer;

int Find(int x) {
    if(x == root[x]) return x;
    return root[x] = Find(root[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if(x!=y) root[y] = x;
}

int dfs(int curr, int cnt, int n) {
    if(cnt == n-1)
        return 1;
    
    for(int i=0; i<(int)adjList[curr].size(); i++) {
        int next = adjList[curr][i].first;
        int cost = adjList[curr][i].second;
        
        if(visited[next]) continue;
        visited[next] = true;
        answer += cost;
        if(dfs(next, cnt+1, n)) return 1;
    }
    
    return 0;
}

int solution(int n, vector<vector<int>> costs) {
    vector<tuple<int, int, int>> edge;
    
    for(int i=0; i<=n; i++) root[i] = i;
    
    for(int i=0; i<(int)costs.size(); i++) {
        edge.push_back({costs[i][2], costs[i][0], costs[i][1]});
    }
    
    sort(edge.begin(), edge.end());
    
    for(int i=0; i<(int)edge.size(); i++) {
        int c = get<0>(edge[i]);
        int a = get<1>(edge[i]);
        int b = get<2>(edge[i]);
        
        if(Find(a) == Find(b)) continue;
        Union(a, b);
        adjList[a].push_back({b, c});
        adjList[b].push_back({a, c});
    }
    
    visited[0] = true;
    dfs(0, 0, n);
    
    return answer;
}