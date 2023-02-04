#include <string>
#include <vector>
#include <iostream>
using namespace std;

int perc[4] = {40, 30, 20, 10};
int N; // 이모티콘 개수
int perm[7]; // 적용할 퍼센트를 저장한 순열
pair<int, int> p_emo[7]; // 퍼센트를 적용한 이모티콘 정보 {퍼센트, 퍼센트를 적용한 가격}
pair<int, int> ans = {0, 0}; // 정답을 저장할 임시 변수

// 이모티콘 플러스의 가입 여부를 판단하는 함수
// return : {이모티콘 플러스 가입 여부, 판매액}
// {true, 0} : 이모티콘 플러스에 가입함
// {false, sum} : 이모티콘 플러스에 가입하지 않으며 sum원 판매함
pair<bool, int> joinEmoPlus(int p, int d) {
    int sum = 0;
        
    for(int i=0; i<N; i++) {
        if(p > p_emo[i].first) continue;
        sum += p_emo[i].second;
    }
        
    if(d <= sum) return {true, 0};
    return {false, sum};
}

// 중복 순열을 만드는 함수
void makePermutation(int cnt, vector<vector<int>> users, vector<int> emoticons) {
    if(cnt == N) {
        int plus = 0;
        int sum = 0;
        
        // 만든 순열의 할인율을 각 이모티콘에 적용한다.
        for(int i=0; i<N; i++) {
            // p_emo[i] = {perm[i], emoticons[i] * (1 - perm[i]*0.01)}; 13, 15, 18 X
            p_emo[i] = {perm[i], emoticons[i] * (100-perm[i]) / 100};
        }
        
        // 각 사용자가 이모티콘 플러스에 가입하면 plus를 1 증가시키고
        // 가입하지 않으면 판매액을 sum에 더한다.
        for(int i=0; i<users.size(); i++) {
            pair<bool, int> result = joinEmoPlus(users[i][0], users[i][1]);
            
            if(result.first) plus++;
            else sum += result.second;
        }
        
        // plus와 sum의 값에 따라 정답을 업데이트한다.
        if(ans.first < plus) {
            ans = {plus, sum};
        } else if(ans.first == plus) {
            if(ans.second < sum) {
                ans = {plus, sum};
            }
        }
        
        return;
    }
    
    // 이모티콘 할인율은 10, 20, 30, 40 중 하나이다.
    for(int i=0; i<4; i++) {
        perm[cnt] = perc[i];
        makePermutation(cnt+1, users, emoticons);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    N = emoticons.size();

    makePermutation(0, users, emoticons);
    
    answer.push_back(ans.first);
    answer.push_back(ans.second);

    return answer;
}