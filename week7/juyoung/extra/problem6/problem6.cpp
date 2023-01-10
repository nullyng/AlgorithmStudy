#include <string>
#include <vector>
#include <queue>
#define INF 20000000
using namespace std;

vector<pair<int, int>> adjList[201];

void dijkstra(int s, vector<int> &dist) {
    priority_queue<pair<int, int>> pq;
    
    pq.push({0, s});
    dist[s] = 0;
    
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if(dist[node] < cost) continue;

        for(int i=0; i<(int)adjList[node].size(); i++) {
            int next = adjList[node][i].first;
            int fares = adjList[node][i].second;
            int new_cost = cost + fares;

            if(dist[next] > new_cost) {
              dist[next] = new_cost;
              pq.push({-new_cost, next});
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    
    for(int i=0; i<(int)fares.size(); i++) {
        int c = fares[i][0];
        int d = fares[i][1];
        int f = fares[i][2];
        
        adjList[c].push_back({d, f});
        adjList[d].push_back({c, f});
    }
    
    vector<int> dist_s(n+1, INF);
    dijkstra(s, dist_s);
    
    vector<int> dist_a(n+1, INF);
    dijkstra(a, dist_a);
    
    vector<int> dist_b(n+1, INF);
    dijkstra(b, dist_b);
    
    for(int i=1; i<=n; i++)
        answer = min(answer, dist_s[i] + dist_a[i] + dist_b[i]);
    
    return answer;
}