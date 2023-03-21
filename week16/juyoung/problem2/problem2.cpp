#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
int arr[1001][1001];
int edge;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;

  string temp;
  for (int i = 1; i <= n; i++) {
    cin >> temp;
    for (int j = 1; j <= m; j++) {
      arr[i][j] = temp[j-1] - '0';
      if (arr[i - 1][j - 1]>0 && arr[i - 1][j]>0 && arr[i][j - 1]>0 && arr[i][j]>0)
        arr[i][j] = min(min(arr[i - 1][j - 1], arr[i - 1][j]), arr[i][j - 1]) + 1;
      edge = max(edge, arr[i][j]);
    }
  }

  cout << edge * edge << "\n";
  return 0;
}