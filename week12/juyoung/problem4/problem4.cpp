#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N, input;
  vector<int> up, down;
  int zero = 0, answer = 0;

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> input;
    if(input == 1) answer++;
    else if(input == 0) zero++;
    else if (input > 0) up.push_back(input);
    else down.push_back(input);
  }

  sort(up.begin(), up.end(), greater<>());
  sort(down.begin(), down.end());

  if(up.size()%2 == 1) up.push_back(1);
  if(down.size()%2 == 1) down.push_back(zero > 0 ? 0 : 1);

  for (int i = 0; i < up.size(); i += 2)
    answer += up[i] * up[i + 1];

  for (int i = 0; i < down.size(); i += 2)
    answer += down[i] * down[i + 1];

  cout << answer << "\n";
  return 0;
}