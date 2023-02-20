#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

typedef unordered_set<int> us;

vector<us> dp;

int getContNumber(int N, int cnt) {
    int result = 0;
    int n = N;

    while (cnt > 0) {
        result += n;
        n *= 10;
        cnt--;
    }

    return result;
}

int getResult(int c, int n1, int n2) {
    int result = 0;

    switch (c) {
    case 0:
        result = n1 + n2;
        break;
    case 1:
        result = n1 - n2;
        break;
    case 2:
        result = n1 * n2;
        break;
    case 3:
        result = n1 / n2;
        break;
    }

    return result;
}

bool calc(int n, int number) {
    int i = 1;
    int j = n - 1;
    bool included = false;

    while (i < n && j > 0) {
        for (us::iterator _i = dp[i].begin(); _i != dp[i].end(); _i++) {
            for (us::iterator _j = dp[j].begin(); _j != dp[j].end(); _j++) {
                for (int c = 0; c < 4; c++) {
                    int result = getResult(c, *_i, *_j);

                    if (result <= 0) continue;

                    dp[n].insert(result);
                }
            }
        }
        i++;
        j--;
    }

    if (dp[n].find(number) != dp[n].end())
        included = true;

    return included;
}

int solution(int N, int number) {
    int answer = 0;
    int idx = 1;

    dp.assign(9, unordered_set<int>());

    while (idx < 9) {
        int contNumber = getContNumber(N, idx);

        dp[idx].insert(contNumber);
        if (calc(idx, number)) break;

        idx++;
    }

    if (idx > 8) idx = -1;
    answer = idx;

    return answer;
}

int main() {
    int answer = solution(5, 5);

    return 0;
}