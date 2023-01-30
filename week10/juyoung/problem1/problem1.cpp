#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int> m;
    int ty = stoi(today.substr(0, 4));
    int tm = stoi(today.substr(5, 2));
    int td = stoi(today.substr(8, 2));
    
    for(int i=0; i<terms.size(); i++) {
        char type = terms[i].substr(0, 1)[0];
        int month = stoi(terms[i].substr(2));
        m[type] = month;
    }
    
    for(int i=0; i<privacies.size(); i++) {
        int year = stoi(privacies[i].substr(0, 4));
        int month = stoi(privacies[i].substr(5, 2));
        int date = stoi(privacies[i].substr(8, 2));
        char type = privacies[i].substr(11)[0];
        
        if(--date == 0) {
            date = 28;
            if(--month == 0) {
                year--;
                month = 12;
            }
        }
        
        int temp = m[type]/12;
        month += m[type]%12;
        year += temp;
        if(month > 12) {
            year++;
            month -= 12;
        }
        
        if(year < ty) {
            answer.push_back(i+1);
        } else if(year == ty) {
            if(month < tm) {
                answer.push_back(i+1);
            } else if(month == tm) {
                if(date < td) {
                    answer.push_back(i+1);
                }
            }
        }
    }
    
    return answer;
}