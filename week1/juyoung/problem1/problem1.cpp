#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
  int N, M;
  string input;
  map<string, int> m;
  int answer = 0;

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> input;
    m[input]++;
  }

  for (int i = 0; i < M; i++) {
    cin >> input;
    if(m[input]) answer++;
  }

  cout << answer << "\n";

  return 0;
}