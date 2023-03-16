#include <iostream>
using namespace std;

int N, M, A;
long long sum, answer;
long long cnt[1001];

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> N >> M;
   
    for(int i=0; i<N; i++) {
        cin >> A;
        sum += A;
        cnt[sum%M]++;
    }
    
    for(int i=0; i<1001; i++) answer += cnt[i]*(cnt[i]-1)/2;
    answer += cnt[0];
    
    cout << answer << "\n";
    return 0;
}