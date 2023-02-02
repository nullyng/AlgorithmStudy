#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string toBinary(long long number) {
    string binary = "";

    while (number) {
        int remain = number % 2;
        binary += (remain + '0');
        number /= 2;
    }

    int len = (int)binary.length();
    int tree = 2;

    while (1) {
        if (len <= tree - 1) {
            for (int j = 0; j < (tree - 1) - len; j++)
                binary.push_back('0');
            break;           
        }

        tree *= 2;
    }

    reverse(binary.begin(), binary.end());

    return binary;
}

int search(string tree, int s, int e) {
    if (s == e) return 1;

    int p = (s + e) / 2;
    int lc = (s + p) / 2;
    int rc = (p + e + 1) / 2;

    if (tree[p] == '0' && (tree[lc] == '1' || tree[rc] == '1'))
        return 0;

    int l = search(tree, s, p - 1);
    int r = search(tree, p + 1, e);

    if (l && r) return 1;
    else return 0;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;

    for (long long number : numbers) {
        string tree = toBinary(number);
        int result = search(tree, 0, tree.length() - 1);
        answer.push_back(result);
    }

    return answer;
}

int main() {
    vector<long long> numbers = { 7, 42, 5, 495 };
    vector<int> answer = solution(numbers);
}