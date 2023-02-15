#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int idx = 0;
        
    sort(people.begin(), people.end());
    while(idx < people.size()) {
        if(people[idx]+people[people.size()-1] <= limit) {
            answer++;
            idx++;
        } else {
            answer++; 
        }
        people.pop_back();
    }
    
    return answer;
}