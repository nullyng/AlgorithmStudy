#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#define INF 1e9
using namespace std;

int K, N, M;
int a, b, t, h;
int A, B;
vector<tuple<int, int, int>> adjList[2001];
int dist[2001][201];
int answer = INF;

void dijkstra() {
    priority_queue<tuple<int, int, int>> pq;
    
    pq.push({0, K, A});
    dist[A][K] = 0;
    
    while(!pq.empty()) {
        int ti = -get<0>(pq.top());
        int th = get<1>(pq.top());
        int curr = get<2>(pq.top());
        pq.pop();
        
        if(dist[curr][th] < ti) continue;
        
        for(int i=0; i<adjList[curr].size(); i++) {
            tuple<int, int, int> v = adjList[curr][i];
            int next = get<0>(v);
            int new_ti = ti + get<1>(v);
            int new_th = th - get<2>(v);
            
            if(new_th <= 0) continue;
            if(new_ti < dist[next][new_th]) {
                dist[next][new_th] = new_ti;
                pq.push({-new_ti, new_th, next});
            }
        }
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> K >> N >> M;
    
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=K; j++) {
            dist[i][j] = INF;
        }
    }
    
    for(int i=0; i<M; i++) {
        cin >> a >> b >> t >> h;
        adjList[a].push_back({b, t, h});
        adjList[b].push_back({a, t, h});
    }
    
    cin >> A >> B;
    
    dijkstra();
    
    for(int j=1; j<=K; j++) {
        answer = min(answer, dist[B][j]);
    }
    
    if(answer != INF) cout << answer;
    else cout << -1;
    cout << "\n";
    
    return 0;
}
