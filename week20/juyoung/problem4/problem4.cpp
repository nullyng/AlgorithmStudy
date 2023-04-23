#include <iostream>
#include <string>

using namespace std;

int main() {
    int N, K;
    string answer = "";
    
    cin >> N >> K;
    
    int A = 1, B = N-1;
    while(A*B < K) {
        if(B<0) {
            cout << "-1\n";
            return 0;
        }
        A++; B--;
    }
    
    for(int i=0; i<N; i++) answer += "B";
    
    for(int i=0; i<A-1; i++) answer[i] = 'A';
    int curr = (A-1)*B;
    answer[N-(K-curr)-1] = 'A';
    
    if(answer.length() == 0) cout << "-1\n";
    else cout << answer << "\n";

    return 0;
}
