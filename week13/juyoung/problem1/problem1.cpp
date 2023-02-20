#include <vector>
#include <set>

using namespace std;

int repeat_n(int N, int idx) {
    int result = N;
    for(int i=1; i<=idx; i++) result = result*10+N;
    return result;
}

int solution(int N, int number) {
    if(N == number) return 1;
    
    set<int> dp[8];
    
    dp[0].insert(N);
    for(int idx=1; idx<8; idx++) {
        dp[idx].insert(repeat_n(N, idx));
        
        for(int i=0; i<idx; i++) {
            for(int j=0; j<idx; j++) {
                if(i+j+1 != idx) continue;
                
                for(int n1 : dp[i]) {
                    for(int n2 : dp[j]) {
                        dp[idx].insert(n1+n2);
                        dp[idx].insert(n1*n2);
                        if(n1-n2>0) dp[idx].insert(n1-n2);
                        if(n1/n2>0) dp[idx].insert(n1/n2);
                    }
                }
            }
        }
        
        if(dp[idx].find(number)!=dp[idx].end()) return idx+1;
    }
    
    return -1;
}