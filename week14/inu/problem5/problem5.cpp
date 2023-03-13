#include <string>
#include <vector>

using namespace std;

int alphabet[26];

int solution(string name) {
    int answer = 0;
    int len = (int)name.length();
    int move = len - 1;
    
    // 문자별 조이스틱 조작 횟수
    for(int i = 0; i < 13; i++) {
        alphabet[i] = i;
        alphabet[i + 13] = 13 - i;
    }
    
    for(int i = 0; i < len; i++) {
        answer += alphabet[name[i] - 'A'];
        
        if(i + 1 < len && name[i + 1] == 'A') {
            int endA = i + 1;
            
            while(endA < len && name[endA] == 'A') endA++;
            
            move = min(move, (i * 2) + (len - endA));
            move = min(move, i + (len - endA) * 2);
        }
    }
    
    return answer + move;
}