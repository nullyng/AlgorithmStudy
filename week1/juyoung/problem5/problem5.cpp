#include <string>
#include <stack>

using namespace std;

bool isValid(string s) {
    stack<char> st;
    int sCnt, mCnt, lCnt;
    
    sCnt = mCnt = lCnt = 0;
    
    for(int i=0; i<(int)s.length(); i++) {
        if(s[i] == '(') { st.push('('); sCnt++; }
        else if(s[i] == '{') { st.push('{'); mCnt++; }
        else if(s[i] == '[') { st.push('['); lCnt++; }
        else if(s[i] == ')') { if(!st.empty() && st.top() == '(') st.pop(); sCnt--; }
        else if(s[i] == '}') { if(!st.empty() && st.top() == '{') st.pop(); mCnt--; }
        else if(s[i] == ']') { if(!st.empty() && st.top() == '[') st.pop(); lCnt--; }
    }
    
    if(st.empty() && !sCnt && !mCnt && !lCnt) return true;
    else return false;
}

int solution(string s) {
    int answer = 0;
    
    for(int i=0; i<(int)s.length(); i++) {
        if(isValid(s)) answer++;
        s = s.substr(1) + s[0];
    }
    
    return answer;
}