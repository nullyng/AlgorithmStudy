#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int len = (int)number.length() - k;
    int idx = 0;

    for (int i = 0; i < len; i++) {
        int m = idx;

        for (int j = idx; j <= i + k; j++) {
            if (number[j] > number[m])
                m = j;
        }

        answer += number[m];
        idx = m + 1;
    }

    return answer;
}

int main() {
    string number = "1231234";
    string answer = solution(number, 3);
    return 0;
}