#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9
#define ll long long
using namespace std;

int N, M, C;
int A, B, D;
vector<pair<int, int>> park[100001];
ll dist[100001];
ll sum;
bool isConnected[100001];
ll answer;

void dijkstra() {
    priority_queue<pair<ll, int>> pq;
    
    pq.push({0, 1});
    dist[1] = 0;
    
    while(!pq.empty()) {
        ll d = -pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        
        if(isConnected[curr]) continue;
        if(dist[curr] < d) continue;
        isConnected[curr] = true;
        
        for(auto p : park[curr]) {
            if(isConnected[p.first]) sum -= p.second;
        }
        answer = min(answer, sum + C*dist[curr]);
        
        for(auto p : park[curr]) {
            int next = p.first;
            ll new_dist = p.second + d;
            
            if(new_dist < dist[next]) {
                dist[next] = new_dist;
                pq.push({-new_dist, next});
            }
        }
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> N >> M >> C;
    
    for(int i=1; i<=N; i++) dist[i] = INF;
    
    for(int i=0; i<M; i++) {
        cin >> A >> B >> D;
        park[A].push_back({B, D});
        park[B].push_back({A, D});
        sum += D;
    }
    
    answer = sum;
    dijkstra();
    
    cout << answer << "\n";
    return 0;
}
