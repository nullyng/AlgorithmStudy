#include <string>
#include <vector>
#define TERM 11

using namespace std;

int _terms[26];

int toNumber(string s) {
    string new_s = s.substr(0, 4) + s.substr(5, 2) + s.substr(8, 2);
    return stoi(new_s);
}

string toString(int year, int month, int day) {
    string s_year = to_string(year);
    string s_month = to_string(month);
    string s_day = to_string(day);

    if (s_month.length() < 2) {
        s_month = '0' + s_month;
    }

    if (s_day.length() < 2) {
        s_day = '0' + s_day;
    }

    return s_year + s_month + s_day;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int n_today = toNumber(today);
    
    // 약관 기간 저장
    for (string term : terms) {
        int idx = term[0] - 'A';
        _terms[idx] = stoi(term.substr(2, 3));
    }

    int idx = 1;

    for (string privacy : privacies) {
        int year = stoi(privacy.substr(0, 4));
        int month = stoi(privacy.substr(5, 2));
        int day = stoi(privacy.substr(8, 2));
        int term = _terms[privacy[TERM] - 'A'];

        month += term;

        if (month > 12) {
            year += (month / 12);
            month %= 12;
            if (month == 0) {
                month = 12;
                year--;
            }
        }

        if (--day == 0) {
            day = 28;
            if (--month == 0) {
                month = 12;
                year--;
            }
        }

        string str = toString(year, month, day);
        int valid = stoi(str);

        if (valid < n_today)
            answer.push_back(idx);

        idx++;
    }

    return answer;
}

int main() {
    string today = "2019.01.01";
    vector<string> terms = { "b 12" };
    vector<string> privacies = { "2017.12.21 b"};

    vector<int> answer = solution(today, terms, privacies);

    return 0;
}

//string today = "2022.05.19";
//vector<string> terms = { "A 6", "B 12", "C 3" };
//vector<string> privacies = { "2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C" };

//string today = "2019.01.01";
//vector<string> terms = { "B 12" };
//vector<string> privacies = { "2017.12.21 B"};