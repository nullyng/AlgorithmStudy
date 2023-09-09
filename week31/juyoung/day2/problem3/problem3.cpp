#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;

int N;
char map[6][6];
int minValue, maxValue;

void dfs(int y, int x, char op, int value) {
  if(map[y][x] < '0' || map[y][x] > '5') op = map[y][x];
  else {
    int number = map[y][x] - '0';
    if(op == ' ') value = number;
    else if(op == '+') value += number;
    else if(op == '-') value -= number;
    else value *= number;
  }

  if(y == N && x == N) {
    minValue = min(value, minValue);
    maxValue = max(value, maxValue);
    return;
  }

  if(y <= N) dfs(y + 1, x, op, value);
  if(x <= N) dfs(y, x + 1, op, value);
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> map[i][j];
    }
  }

  minValue = INF; maxValue = -INF;
  dfs(1, 1, ' ', 0);

  cout << maxValue << " " << minValue << "\n";
  return 0;
}