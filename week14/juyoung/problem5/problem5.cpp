#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int len = name.length();
    int move = len-1;
    
    for(int curr=0; curr<len; curr++) {
        answer += min(name[curr]-'A', 'Z'-name[curr]+1);
        
        int next;
        for(next=curr+1; next<len; next++)
            if(name[next] > 'A') break;
        
        move = min(move, min(2*curr+len-next, 2*len-2*next+curr));
    }
    
    answer += move;
    
    return answer;
}