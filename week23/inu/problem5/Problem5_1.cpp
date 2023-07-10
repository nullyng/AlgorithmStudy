#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

string seq;
vector<pair<int, int>> brackets;
set<string> result;
bool isChecked[200];

void comb(int i) {
    if (i >= (int)brackets.size()) {
        string str = "";

        for (int i = 0; i < (int)seq.length(); i++)
            if (!isChecked[i]) str += seq[i];

        if (seq.compare(str)) result.insert(str);

        return;
    }

    isChecked[brackets[i].first] = true;
    isChecked[brackets[i].second] = true;
    comb(i + 1);

    isChecked[brackets[i].first] = false;
    isChecked[brackets[i].second] = false;
    comb(i + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    stack<int> st;

    cin >> seq;

    for (int i = 0; i < (int)seq.length(); i++) {
        if (seq[i] == '(')
            st.push(i);
        else if (seq[i] == ')') {
            brackets.push_back({ st.top(), i });
            st.pop();
        }
    }

    comb(0);

    for (auto str : result)
        cout << str << '\n';

    return 0;
}