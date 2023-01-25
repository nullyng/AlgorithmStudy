#include <iostream>
using namespace std;

int N;
int dist[21][21];
bool noRoute[21][21];

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++)
      cin >> dist[i][j];
  }

  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if(i==j || i==k || j==k) continue;
        if (dist[i][j] > dist[i][k] + dist[k][j]) {
          cout << "-1\n";
          return 0;
        }
        else if(dist[i][j] == dist[i][k] + dist[k][j]) noRoute[i][j] = true;
      }
    }
  }

  int answer = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (noRoute[i][j]) continue;
			answer += dist[i][j];
		}
	}

  cout << answer << "\n";
  return 0;
}