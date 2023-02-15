#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int weight[241];

void FindWeight(int w1, int w2) {
    if (weight[w2]) {
        weight[w2]--;
        return;
    }
    
    int remain = w2;

    for (int w = w2 - 1; w >= 40;) {
        if (!weight[w]) {
            w--;
            continue;
        }

        weight[w]--;
        remain -= w;
        w = remain;
    }
}

int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(), people.end());

    for (int w : people)
        weight[w]++;

    for (int i = (int)people.size() - 1; i >= 0; i--) {
        int w1 = people[i];
        int w2 = limit - w1;

        if (weight[w1]) {
            weight[w1]--;

            if (w2 >= 40) {
                FindWeight(w1, w2);
            }

            answer++;
        }
    }

    return answer;
}

int main() {
    vector<int> people = { 40, 50, 150, 160 };
    int answer = solution(people, 200);

    return 0;
}