#include <iostream>
#include <cstring>
using namespace std;

int T, N;
int button[5] = {60, 10, -10, 1, -1};
int answer[5];

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> T;
    while(T--) {
        cin >> N;
        
        memset(answer, 0, sizeof(answer));
        
        answer[0] += N/60;
        N -= N/60*60;
        
        if(N<=35) {
            if(N%10<=5) {
                answer[1] += N/10;
                answer[3] += N%10;
            } else {
                answer[1] += N/10+1;
                answer[4] += 10-N%10;
            }
        } else {
            answer[0]++;
            
            if(N%10<5) {
                answer[2] += 6-N/10;    
                answer[3] += N%10;
            } else {
                answer[2] += 6-N/10-1;
                answer[4] += 10-N%10;
            }
        }
        
        for(int i=0; i<5; i++) cout << answer[i] << " ";
        cout << "\n";
    }

    return 0;
}
