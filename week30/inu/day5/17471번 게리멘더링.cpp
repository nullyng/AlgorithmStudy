#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int answer = 1000;
int person[11];
bool checked[11];
vector<int> graph[11];

int getSumOfCities(int n, int cnt) {
  bool flag = checked[n];
  int sum = person[n];
  int connected = 1;
  bool visited[11] = { false, };
  queue<int> q;

  visited[n] = true;
  q.push(n);

  while(!q.empty()) {
    int u = q.front();
    q.pop();

    for(int i = 0; i < (int)graph[u].size(); i++) {
      int v = graph[u][i];
      if(checked[v] == flag && !visited[v]) {
        visited[v] = true;
        connected++;
        sum += person[v];
        q.push(v);
      }
    }
  }

  if(cnt != connected)
    sum = -1;

  return sum;
}

vector<int> getNodes() {
  vector<int> u;

  for(int i = 1; i <= N; i++)
    if(checked[i]) {
      u.push_back(i);
      break;
    }
  
  for(int j = 1; j <= N; j++)
    if(!checked[j]) {
      u.push_back(j);
      break;
    }
  
  return u;
}

void comb(int cur, int cnt) {
  if(cur > N) {
    if(cnt > 0 && cnt < N) {
      vector<int> u = getNodes();
      int sum1 = getSumOfCities(u[0], cnt);
      int sum2 = getSumOfCities(u[1], N - cnt);
      if(sum1 > 0 && sum2 > 0) {
        answer = min(answer, abs(sum1 - sum2));
      }
    }

    return;
  }

  checked[cur] = true;
  comb(cur + 1, cnt + 1);
  checked[cur] = false;
  comb(cur + 1, cnt);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  for(int i = 1; i <= N; i++)
    cin >> person[i];

  for(int u = 1; u <= N; u++) {
    int n;
    cin >> n;

    for(int j = 0; j < n; j++) {
      int v;
      cin >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
  }

  comb(1, 0);

  if(answer == 1000) answer = -1;

  cout << answer;

  return 0;
}