#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> combs = {
  {0, 1, 2},
  {0, 1, 3},
  {0, 2, 4},
  {0, 3, 4},
  {5, 1, 2},
  {5, 1, 3},
  {5, 2, 4},
  {5, 3, 4}
};

vector<int> findMinComb(vector<int> numbers) {
  vector<int> minComb;
  int minSum = 151;

  for(int i = 0; i < 8; i++) {
    int sum = 0;
    vector<int> comb;
    
    for(int n : combs[i]) {
      sum += numbers[n];
      comb.push_back(numbers[n]);
    }
    
    if(sum < minSum) {
      minSum = sum;
      minComb = comb;
    }
  }

  sort(minComb.begin(), minComb.end());

  return minComb;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  vector<int> numbers(6);
  long long N;
  long long sum = 0;

  cin >> N;

  for(int i = 0; i < 6; i++)
    cin >> numbers[i];
  
  if(N == 1) {
    sort(numbers.begin(), numbers.end());

    for(int i = 0; i < 5; i++)
      sum += numbers[i];
  }
  else {
    vector<int> comb = findMinComb(numbers);
    
    long long x = comb[0] * (5 * N * N - 8 * N + 4);
    long long y = comb[1] * 8 * (N - 1);
    long long z = comb[2] * 4;

    sum = x + y + z;
  }
  
  cout << sum;

  return 0;
}