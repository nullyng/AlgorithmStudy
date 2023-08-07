#include <iostream>
using namespace std;

int N;
int value[100001];

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> value[i];

  int left = 0, right = N - 1;
  int sum = 2e9;
  pair<int, int> answer;

  while (left < right) {
    int temp = value[left] + value[right];

    if(abs(sum) > abs(temp)) {
      sum = temp;
      answer.first = value[left];
      answer.second = value[right];
    }

    if(temp == 0) break;
    else if(temp > 0) right--;
    else left++;
  }

  cout << answer.first << " " << answer.second << "\n";
  return 0;
}