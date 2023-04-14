#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#define INF 1e9
using namespace std;

int K, N, R, s, d, l, t;
vector<tuple<int, int, int>> graph[101];
int dist[101][10001];
int answer = INF;

void dijkstra() {
    priority_queue<tuple<int, int, int>> pq;
    
    pq.push({0, K, 1});
    dist[1][K] = 0;
    
    while(!pq.empty()) {
        int len = -get<0>(pq.top());
        int fee = get<1>(pq.top());
        int curr = get<2>(pq.top());
        pq.pop();
        
        if(dist[curr][fee] < len) continue;
        
        for(auto g : graph[curr]) {
            int next = get<0>(g);
            int new_len = len + get<1>(g);
            int new_fee = fee - get<2>(g);
            
            if(new_fee < 0) continue;
            if(new_len < dist[next][new_fee]) {
                dist[next][new_fee] = new_len;
                pq.push({-new_len, new_fee, next});
            }
        }
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> K >> N >> R;
    
    for(int i=1; i<=N; i++) {
        for(int j=0; j<=10000; j++)
            dist[i][j] = INF;
    }
    
    for(int i=0; i<R; i++) {
        cin >> s >> d >> l >> t;
        graph[s].push_back({d, l, t});
    }
    
    dijkstra();
    
    for(int i=0; i<=10000; i++)
        answer = min(answer, dist[N][i]);

    if(answer == INF) cout << "-1\n";
    else cout << answer;
    
    return 0;
}
