#include <iostream>
#include <queue>
#define MAX 1000
#define T 10000000
#define INF 10001000000

using namespace std;

typedef long long ll;

int subway[MAX][MAX];
int company[MAX];
ll dist[MAX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N, M;

  cin >> N >> M;

  for(int i = 0; i < N; i++) {
    cin >> company[i];
    dist[i] = INF;
  }

  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++) {
      cin >> subway[i][j];
      if(subway[i][j] && company[i] != company[j])
        subway[i][j] += T;
    }
      
  queue<pair<int, ll>> q;
  q.push({0, 0});
  dist[0] = 0;
  
  while(!q.empty()) {
    int u = q.front().first;
    ll w = q.front().second;
    q.pop();

    if(u == M || dist[u] < w) continue;

    for(int i = 0; i < N; i++) {
      if(!subway[u][i] || u == i) continue;
      
      int v = i;
      ll w = subway[u][i];
      
      if(dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        q.push({v, dist[v]});
      }
    }
  }

  int t = dist[M] / T;
  int time = dist[M] % T;

  cout << t << ' ' << time;

  return 0;
}