#include <string>
#include <vector>

using namespace std;

int max_plus = 0;
int max_money = 0;
vector<vector<int>> infos;
vector<int> emos;

void backTracking(vector<int> pers, int cnt) {
    if (cnt == (int)emos.size()) {
        int plus = 0;
        int money = 0;

        for (vector<int> info : infos) {
            bool over = false;
            int sum = 0;
            int per = info[0];
            int price = info[1];

            for (int i = 0; i < cnt; i++) {
                if (pers[i] < per) continue;

                sum += (int)(emos[i] * (1 - (float)pers[i] / 100));

                if (sum >= price) {
                    over = true;
                    break;
                }
            }

            if (over) plus++;
            else money += sum;
        }

        if (plus > max_plus) {
            max_plus = plus;
            max_money = money;
        }
        else if (plus == max_plus) {
            max_money = max(max_money, money);
        }

        return;
    }

    for (int i = 10; i <= 40; i += 10) {
        pers.push_back(i);
        backTracking(pers, cnt + 1);
        pers.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;

    for (vector<int> user : users)
        infos.push_back(user);

    for (int emoticon : emoticons)
        emos.push_back(emoticon);

    backTracking(vector<int>(), 0);

    answer.push_back(max_plus);
    answer.push_back(max_money);

    return answer;
}

int main() {
    vector<vector<int>> users = {
        {40, 10000},
        {25, 10000}
    };

    vector<int> emoticons = {
        7000, 9000
    };

    vector<int> answer = solution(users, emoticons);
}

//{
//        {40,2900},
//        {23, 10000},
//        {11,5200},
//        {5,5900},
//        {40,3100},
//        {27,9200},
//        {32,6900}
//    };