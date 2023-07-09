#include <iostream>
using namespace std;

int n;
int num[300001];

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; i++) cin >> num[i];

  long long answer = num[n-1];
  for (int i = n - 2; i >= 0; i--) {
    if(answer%num[i] == 0) continue;
    long long temp = answer / num[i] + 1;
    answer = temp * num[i];
  }

  cout << answer << "\n";
  return 0;
}