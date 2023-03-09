#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, len;
    cin >> T;
    for(int i = 0; i < T; i++){
        vector<int> nums;
        string commend, s, temp;
        cin >> commend >> len >> s;
        s.erase(0, 1);
        s.pop_back();
        for(auto c: s){
            if(c == ',') {
                nums.push_back(stoi(temp)); temp.clear();
            }
            else temp += c;
        }
        if(!temp.empty()) nums.push_back(stoi(temp));

        int frontDelete = 0, backDelete = 0;
        bool isReversed = false;
        for(auto c : commend) {
            if(c == 'R') isReversed = !isReversed;
            else isReversed ? backDelete++ : frontDelete++;
        }
        if(frontDelete + backDelete > nums.size()) {
            cout << "error" << endl;
            continue;
        }
        nums.erase(nums.begin(), nums.begin() + frontDelete);
        nums.erase(nums.end() - backDelete, nums.end());

        if(isReversed) reverse(nums.begin(), nums.end());
        cout << "[";
        for(int i = 0; i < nums.size(); i++) {
            cout << nums[i];
            if(i != nums.size() - 1) cout << ',';
        }
        cout << "]\n";

    }
    return 0;
}
