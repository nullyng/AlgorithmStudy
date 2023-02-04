#include <string>
#include <vector>
#include <sstream>
using namespace std;

string table[51][51];
pair<int, int> root[51][51];

vector<string> split(string input) {
    vector<string> result;
    stringstream ss(input);
    string temp;

    while(getline(ss, temp, ' ')) {
      result.push_back(temp);
    }

    return result;
}

pair<int, int> Find(pair<int, int> x) {
  int r = x.first, c = x.second;

  if (x == root[r][c]) return {r, c};
  return root[r][c] = Find(root[r][c]);
}

void update(int r, int c, string value) {
    pair<int, int> p = Find({r, c});
    table[p.first][p.second] = value;
}

void updateAll(string v1, string v2) {
    for(int i=1; i<=50; i++) {
        for(int j=1; j<=50; j++) {
            if(table[i][j] == v1)
                table[i][j] = v2;
        }
    }
}

void merge(int r1, int c1, int r2, int c2) {
    pair<int, int> x = Find({r1, c1});
    pair<int, int> y = Find({r2, c2});
    
    if(x == y) return;
    
    int px = x.first, py = x.second;
    int cx = y.first, cy = y.second;
    string value = table[px][py];

    if(table[px][py] == "EMPTY" && table[cx][cy] != "EMPTY")
        value = table[cx][cy];

    for(int i=1; i<=50; i++) {
        for(int j=1; j<=50; j++) {
            if(root[i][j].first == cx && root[i][j].second == cy) {
                root[i][j] = {px, py};
                table[i][j] = "EMPTY";
            }
        }
    }
    
    table[px][py] = value;
}

void unmerge(int r, int c) {
    pair<int, int> p = Find({r, c});
    int x = p.first, y = p.second;
    string value = table[x][y];
    
    for(int i=1; i<=50; i++) {
        for(int j=1; j<=50; j++) {
            pair<int, int> temp = Find({i, j});
            if (temp.first == x && temp.second == y) {
                root[i][j] = {i, j};
                table[i][j] = "EMPTY";
            }
        }
    }
    
    table[r][c] = value;
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    
    for(int i=1; i<=50; i++) {
        for(int j=1; j<=50; j++) {
            root[i][j] = {i, j};
            table[i][j] = "EMPTY";
        }
    }
    
    for(int i=0; i<commands.size(); i++) {
        vector<string> cmd = split(commands[i]);

        if(cmd[0] == "UPDATE") {
            if(cmd.size() == 4) {
                int r = stoi(cmd[1]);
                int c = stoi(cmd[2]);

                // 선택한 셀의 값을 value로 변경
                update(r, c, cmd[3]);
            } else {
                // value1을 값으로 가지고 있는 모든 셀의 값을 value2로 변경
                updateAll(cmd[1], cmd[2]);
            }
        } else if(cmd[0] == "MERGE") {
            int r1 = stoi(cmd[1]);
            int c1 = stoi(cmd[2]);
            int r2 = stoi(cmd[3]);
            int c2 = stoi(cmd[4]);

            // 두 셀을 병합
            merge(r1, c1, r2, c2);
        } else if(cmd[0] == "UNMERGE") {
            int r = stoi(cmd[1]);
            int c = stoi(cmd[2]);
            
            // 루트가 같은 셀들의 루트를 전부 초기 상태(자기자신)로 변경
            unmerge(r, c);
        } else if(cmd[0] == "PRINT") {
            int r = stoi(cmd[1]);
            int c = stoi(cmd[2]);
            pair<int, int> p = Find({r, c});

            answer.push_back(table[p.first][p.second]);
        }
    }

    return answer;
}