#include <iostream>
#include <stack>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace std;

string seq;
unordered_map<int, int> brackets;
set<string> result;

void comb(int cur, string str, stack<int> st) {
    if (cur >= (int)seq.length()) {
        result.insert(str);
        return;
    }

    if (seq[cur] == '(') {
        comb(cur + 1, str + '(', st);
        st.push(brackets[cur]);
        comb(cur + 1, str, st);
    }
    else if (seq[cur] == ')') {
        if (!st.empty() && st.top() == cur) {
            st.pop();
            comb(cur + 1, str, st);
        }
        else
            comb(cur + 1, str + ')', st);
    }
    else {
        comb(cur + 1, str + seq[cur], st);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int cnt = 0;
    stack<int> st;

    cin >> seq;

    for (int i = 0; i < (int)seq.length(); i++) {
        if (seq[i] == '(') {
            st.push(i);
        }
        else if (seq[i] == ')') {
            brackets[st.top()] = i;
            st.pop();
        }
    }

    comb(0, "", st);

    result.erase(seq);

    for (set<string>::iterator itr = result.begin(); itr != result.end(); itr++) {
        cout << *itr << '\n';
    }

    return 0;
}