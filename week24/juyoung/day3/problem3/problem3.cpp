#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int a[200001];
int cnt[100001];
int start;
int answer;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  
  cin >> N >> K;
  
  for(int i=0; i<N; i++) {
      cin >> a[i];
      cnt[a[i]]++;
      
      while(cnt[a[i]] > K) cnt[a[start++]]--;
      answer = max(answer, i-start+1);
  }
  
  cout << answer << "\n";
  return 0;
}
