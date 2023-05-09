#include <iostream>
#include <cmath>
using namespace std;

int k, n;
int tree[3000001];
int answer;

int solve(int node) {
  if(node * 2 >= n) {
    // 리프 노드인 경우 
    answer += tree[node];
    return tree[node];
  } else {
    // 리프 노드가 아닌 경우
    int left = solve(node * 2);
    int right = solve(node * 2 + 1);
    answer += abs(left - right) + tree[node];
    return max(left, right) + tree[node];
  }
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> k;
  n = pow(2, k + 1) - 1;
  for (int i = 2; i <= n; i++) cin >> tree[i];
  solve(1);

  cout << answer << "\n";
  return 0;
}