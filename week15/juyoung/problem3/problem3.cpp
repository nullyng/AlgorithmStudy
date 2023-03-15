#include <iostream>
#define MAX 1000000
using namespace std;

int T, N;
long long dp[MAX+1];

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> T;
    
    for(int i=1; i<=MAX; i++) {
        for(int j=i; j<=MAX; j+=i) dp[j] += i;
    }
    
    for(int i=2; i<=MAX; i++) dp[i] += dp[i-1];
    
    for(int i=0; i<T; i++) {
        cin >> N;
        cout << dp[N] << "\n";
    }
     
    return 0;
}