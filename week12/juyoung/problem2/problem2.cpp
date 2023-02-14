#include <string>

using namespace std;

string solution(string number, int k) {
    string answer = number;
    
    for(int i=0; i<answer.length(); i++) {
        if(answer[i] < answer[i+1]) {
            answer = answer.substr(0, i) + answer.substr(i+1);
            if(--k <= 0) break;
            if(i == 0) i--;
            else i-=2;
        }
    }
    
    if(k>0) answer = answer.substr(0, answer.length()-k);
    
    return answer;
}