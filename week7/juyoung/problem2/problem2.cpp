#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

int dist[51];
vector<pair<int, int>> adjList[51];

void dijkstra(vector<vector<int>> road) {
    priority_queue<pair<int, int>> pq;
    
    pq.push({0, 1});
    dist[1] = 0;
    
    while(!pq.empty()) {
        int node = pq.top().second;
        int time = -pq.top().first;
        pq.pop();
        
        for(int i=0; i<(int)adjList[node].size(); i++) {
            int next = adjList[node][i].first;
            int cost = adjList[node][i].second;
            int new_cost = dist[node] + cost;
            
            if(new_cost < dist[next]) {
                dist[next] = new_cost;
                pq.push({-new_cost, next});
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    for(int i=1; i<=N; i++) dist[i] = INF;
    for(int i=0; i<(int)road.size(); i++) {
        int a = road[i][0];
        int b = road[i][1];
        int c = road[i][2];
        
        adjList[a].push_back({b, c});
        adjList[b].push_back({a, c});
    }
    dijkstra(road);
    
    for(int i=1; i<=N; i++) {
        if(dist[i] <= K) answer++;
    }

    return answer;
}