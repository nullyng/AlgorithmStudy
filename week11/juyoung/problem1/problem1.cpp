#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int n;
pair<double, double> star[101];
int parent[101];
vector<tuple<double, int, int>> lines;
double answer = 0;

int Find(int x) {
  if(parent[x] == x) return x;
  return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
  x = Find(x);
  y = Find(y);

  if(x!=y) parent[y] = x;
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n;

  for (int i = 1; i <= n; i++) parent[i] = i;

  for (int i = 1; i <= n; i++) {
    cin >> star[i].first >> star[i].second;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if(i==j) continue;
      double x = star[i].first - star[j].first;
      double y = star[i].second - star[j].second;
      double dist = round(sqrt(x * x + y * y) * 100) / 100;
      lines.push_back({dist, i, j});
    }
  }

  sort(lines.begin(), lines.end());

  for (int i = 0; i < lines.size(); i++) {
    double d = get<0>(lines[i]);
    int a = get<1>(lines[i]);
    int b = get<2>(lines[i]);

    if(Find(a) == Find(b)) continue;
    Union(a, b);
    answer += d;
  }

  cout << answer << "\n";

  return 0;
}