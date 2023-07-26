#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 16;

typedef struct pipe {
  int d;
  int x, y;
}pipe;

int N;
int result = 0;
int house[MAX + 1][MAX + 1];

bool isDiagonal(int x, int y) {
  if(x + 1 > N || y + 1 > N) return false;
  if(house[x][y + 1] || house[x + 1][y] || house[x + 1][y + 1]) return false;
  return true;
}

vector<pipe> getPossiblePipe(pipe p) {
  vector<pipe> possiblePipe;

  switch(p.d) {
    // 가로
    case 0:
      if(p.y + 1 <= N && !house[p.x][p.y + 1]) {
        possiblePipe.push_back({0, p.x, p.y + 1});
      }
      break;
    // 세로
    case 1:
      if(p.x + 1 <= N && !house[p.x + 1][p.y]) {
        possiblePipe.push_back({1, p.x + 1, p.y});
      }
      break;
    // 대각선
    case 2:
      if(p.y + 1 <= N && !house[p.x][p.y + 1]) {
        possiblePipe.push_back({0, p.x, p.y + 1});
      }

      if(p.x + 1 <= N && !house[p.x + 1][p.y]) {
        possiblePipe.push_back({1, p.x + 1, p.y});
      }
  }
  
  if(isDiagonal(p.x, p.y)) {
    possiblePipe.push_back({2, p.x + 1, p.y + 1});
  }

  return possiblePipe;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  for(int i = 1; i <= N; i++)
    for(int j = 1; j <= N; j++)
      cin >> house[i][j];
  
  queue<pipe> q;
  q.push({0, 1, 2});

  while(!q.empty()) {
    pipe p = q.front();
    q.pop();

    if(p.x == N && p.y == N) {
      result++;
      continue;
    }

    vector<pipe> pipes = getPossiblePipe(p);

    for(pipe p : pipes) q.push(p);
  }

  cout << result;

  return 0;
}