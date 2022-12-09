#include <string>
#include <vector>
#include <algorithm>
#define INF 999999
using namespace std;

vector<int> adjList[51];
bool visited[51];
int answer = INF;

bool checkAlphabet(string a, string b) {
    int cnt = 0;
    
    for(int i=0; i<(int)a.length(); i++) 
        if(a[i] != b[i]) cnt++;   
    
    if(cnt == 1) return true;
    else return false;
}

void dfs(int x, int d, string target, vector<string> words) {
    if(words[x] == target) {
        answer = min(answer, d);
        return;
    }
    
    for(int i=0; i<(int)adjList[x].size(); i++) {
        int next = adjList[x][i];
        
        if(visited[next]) continue;
        visited[x] = true;
        dfs(next, d+1, target, words);
        visited[x] = false;
    }
}

int solution(string begin, string target, vector<string> words) {    
    words.push_back(begin);
    for(int i=0; i<(int)words.size(); i++) {
        for(int j=i+1; j<(int)words.size(); j++) {
            if(checkAlphabet(words[i], words[j])) {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
    
    dfs((int)words.size()-1, 0, target, words);
    
    if(answer == INF) return 0;
    else return answer;
}