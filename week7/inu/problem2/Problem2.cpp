#include <iostream>
#include <vector>
#include <queue>
#define INF 999999

using namespace std;

typedef struct edge {
    int v, k;
}edge;

vector<edge> graph[51];
int dist[51];

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    int u, v, k;

    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
    }

    for (vector<int> e : road) {
        u = e[0];
        v = e[1];
        k = e[2];

        graph[u].push_back({ v, k });
        graph[v].push_back({ u, k });
    }

    queue<edge> q;
    q.push({ 1, 0 });
    dist[1] = 0;

    while (!q.empty()) {
        edge e = q.front();
        q.pop();

        u = e.v;

        if (e.k > dist[u])
            continue;

        for (int i = 0; i < (int)graph[u].size(); i++) {
            v = graph[u][i].v;
            k = graph[u][i].k;

            if (dist[u] + k < dist[v]) {
                dist[v] = dist[u] + k;
                q.push({ v, dist[v] });
            }
        }
    }

    for (int i = 1; i <= N; i++)
        if (dist[i] <= K)
            answer++;

    return answer;
}