#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100001
#define INF INT64_MAX

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

vector<pll> adj[MAX];
ll dist[MAX];
bool visited[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, C;
    ll dSum = 0;

    cin >> N >> M >> C;

    // 모든 간선 가중치합을 구함 => 도로 보수 비용
    for (int i = 0; i < M; i++) {
        int A, B, D;
        cin >> A >> B >> D;
        adj[A].push_back({ B, D });
        adj[B].push_back({ A, D });
        dSum += D;
    }

    fill(dist, dist + N + 1, INF);

    ll ans = dSum;
    priority_queue<pll> pq;
    pq.push({ 0, 1 });
    dist[1] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        ll w = -pq.top().first;
        pq.pop();

        if (visited[u]) continue;
        if (dist[u] < w) continue;

        visited[u] = true;

        // 방문했던 정점에 연결된 도로들은 철거하기 때문에 dSum에서 빼줌
        for (pll p : adj[u]) {
            int v = p.first;
            ll c = p.second;
            if (visited[v]) dSum -= c;
        }

        ans = min(ans, w * C + dSum);

        for (pll p : adj[u]) {
            int v = p.first;
            ll c = w + p.second;
            if (dist[v] > c) {
                dist[v] = c;
                pq.push({ -dist[v], v});
            }
        }
    }

    cout << ans;

    return 0;
}