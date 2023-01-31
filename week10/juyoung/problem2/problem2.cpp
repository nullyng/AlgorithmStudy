#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int d = 0;
    int p = 0;
    
    for(int i=n-1; i>=0; i--) {
        d += deliveries[i];
        p += pickups[i];
        
        while(d > 0 || p > 0) {
            d -= cap;
            p -= cap;
            answer += (i+1)*2;
        }
    }
    
    return answer;
}