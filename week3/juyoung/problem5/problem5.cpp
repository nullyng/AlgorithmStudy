#include <iostream>
#include <vector>
#include <algorithm>
#define INF 99999
using namespace std;

int N, M;
int city[50][50];
vector<pair<int, int>> chicken;
vector<pair<int, int>> home;
int selected[13];
int answer = INF;

void makeComb(int cnt, int idx) {
  if(cnt == M) {
    int chicken_dist = 0;

    for(int i=0; i<home.size(); i++) {
      int min_dist = INF;
      for(int j=0; j<M; j++) {
        int dist = abs(home[i].first - chicken[selected[j]].first) + abs(home[i].second - chicken[selected[j]].second);
        min_dist = min(min_dist, dist);
      }
      chicken_dist += min_dist;
    }

    answer = min(answer, chicken_dist);
    return;
  }

  for(int i=idx; i<chicken.size(); i++) {
    selected[cnt] = i;
    makeComb(cnt+1, i+1);
  }
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      cin >> city[i][j];
      if(city[i][j] == 1) home.push_back({i, j});
      else if(city[i][j] == 2) chicken.push_back({i, j});
    }
  }

  makeComb(0, 0);

  cout << answer << "\n";

  return 0;
}