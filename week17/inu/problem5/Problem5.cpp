#include <string>
#include <vector>

using namespace std;

string stringCompression(string s, int unit) {
    string result = "";

    int idx = 0;
    int len = (int)s.length();

    while (idx < len) {
        int cnt = 1;
        int i = idx;
        int j = idx + unit;

        while (j < len) {
            if (s[i] != s[j]) break;

            i++;
            j++;

            if (i == idx + unit) {
                i = idx;
                cnt++;
            }
        }

        if (cnt > 1)
            result += to_string(cnt);

        int last = min(idx + unit, len);

        for (int k = idx; k < last; k++)
            result += s[k];

        idx += (unit * cnt);
    }

    return result;
}

int solution(string s) {
    int answer = 1000;

    for (int unit = 1; unit <= (int)s.length(); unit++) {
        string word = stringCompression(s, unit);
        answer = min(answer, (int)word.length());
    }

    return answer;
}