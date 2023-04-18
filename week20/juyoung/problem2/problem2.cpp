#include <iostream>

using namespace std;

int N;
int B[51];
int answer;

bool isA() {
    bool result = true;
    for(int i=0; i<N; i++) {
        if(B[i] > 0) {
            result = false;
            break;
        }
    }
    return result;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for(int i=0; i<N; i++) cin >> B[i];
    
    while(1) {
        for(int i=0; i<N; i++) {
            if(B[i]%2 == 1) {
                B[i]--;
                answer++;
            }
        }
        
        if(isA()) break;
        
        for(int i=0; i<N; i++) {
            B[i] /= 2;
        }
        answer++;
        
        if(isA()) break;
    }
    
    cout << answer << "\n";

    return 0;
}
