#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.length();
    int len = 1;
    
    while(len <= s.length()/2) {
        string temp = s.substr(0, len);
        int cnt = 1;  // temp로 압축된 문자열 개수
        int comp = 0; // 압축된 문자열의 길이
        
        for(int i=len; i<s.length(); i+=len) {
            if(temp == s.substr(i, len)) cnt++;
            else {
                if(cnt > 1) comp += to_string(cnt).length();
                comp += len;

                temp = s.substr(i, len);
                cnt = 1;
            }
        }
        
        if(cnt > 1) comp += to_string(cnt).length();
        comp += temp.length();
        
        answer = min(answer, comp);
        len++;
    }
    
    return answer;
}