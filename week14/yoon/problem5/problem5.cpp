#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

typedef tuple<int, int, int, int> ti;

int calcAlp(char c) {
    return c - 'A' > 'Z' - c + 1 ? 'Z' - c + 1 : c - 'A';
}

int bfs(vector<int>& a, int find) {
    queue<ti> q; //here, time, find, bitset
    q.push({0, 0, 0, 0});
    while(!q.empty()){
        auto [here, time, found, bit] = q.front();
        q.pop();
        if(a[here] == 1 && !(bit >> here & 1)) {
            found++;
            bit |= 1 << here;
        }
        if(found == find) return time;
        q.push({here - 1 < 0 ? a.size() - 1 : here - 1, time + 1, found, bit});
        q.push({here + 1 > a.size() - 1 ? 0 : here + 1, time + 1, found, bit});
    }
}

int solution(string name) {
    int answer = 0, aNum = 0;
    vector<int> a;
    for(auto c: name) {
        answer += calcAlp(c);
        if(c == 'A') {a.push_back(0); aNum++;}
        else a.push_back(1);
    }
    
    answer += bfs(a, a.size() - aNum);
    return answer;
}