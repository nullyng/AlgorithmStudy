#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
map<pair<char, int>, char> check;

void mapping() {
    check.insert({{'1', 0}, '4'});
    check.insert({{'1', 1}, '2'});
    check.insert({{'1', 2}, '*'});
    check.insert({{'1', 3}, '*'});
    
    check.insert({{'2', 0}, '3'});
    check.insert({{'2', 1}, '*'});
    check.insert({{'2', 2}, '*'});
    check.insert({{'2', 3}, '1'});

    check.insert({{'3', 0}, '*'});
    check.insert({{'3', 1}, '*'});
    check.insert({{'3', 2}, '2'});
    check.insert({{'3', 3}, '4'});

    check.insert({{'4', 0}, '*'});
    check.insert({{'4', 1}, '3'});
    check.insert({{'4', 2}, '1'});
    check.insert({{'4', 3}, '*'});
}

bool move(int idx, string& num, bool isPos, bool isX){
    while(idx < num.size()){
        char res = check.find({num[idx], 2*isPos + isX})->second;
        if(res != '*'){
            num[idx] = res;
            return true;
        }
        else {
            num[idx] = check.find({num[idx], 2*isPos + isX - 2}) == check.end() ? check.find({num[idx], 2*isPos + isX + 2})->second : check.find({num[idx], 2*isPos + isX - 2})->second;
            idx++;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    string num;
    ll x, y;
    cin >> N >> num >> x >> y;
    mapping();
    bool isPosX = x > 0 ? true : false, isPosY = y > 0 ? true : false;
    x = x > 0 ? x : -1 * x; y = y > 0 ? y : -1 * y;
    reverse(num.begin(), num.end());
    string bitX = bitset<51>(x).to_string();
    string bitY = bitset<51>(y).to_string();

    for(int i = bitX.size() - 1; i >= 0; i--){
        if(bitX[i] == '1'){
            if(!move(bitX.size() - i - 1, num, isPosX, true)){
                cout << -1;
                return 0;
            }
        }
        if(bitY[i] == '1'){
            if(!move(bitY.size() - i - 1, num, isPosY, false)){
                cout << -1;
                return 0;
            }
        }
    }
    reverse(num.begin(), num.end());
    cout << num;

    return 0;
}
