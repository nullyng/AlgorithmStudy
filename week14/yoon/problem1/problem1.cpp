#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

void divideAndPrintPreorder(unordered_map<int, int>& idx, vector<int>& inorder, vector<int>& postorder, pi inP, pi poP) {
    if(inP.first > inP.second) return;

    cout << postorder[poP.second] << " ";
    int inorderIdx = idx[postorder[poP.second]];
    divideAndPrintPreorder(idx, inorder, postorder, {inP.first, inorderIdx - 1}, {poP.first, poP.first + (inorderIdx - 1 - inP.first)});
    divideAndPrintPreorder(idx, inorder, postorder, {inorderIdx + 1, inP.second}, {poP.first + (inorderIdx - 1 - inP.first) + 1, poP.second - 1});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, t;
    cin >> N;

    unordered_map<int, int> idx;
    vector<int> inorder, postorder;
    for(int i = 0; i < N; i++){
        cin >> t;
        inorder.push_back(t);
        idx[t] = i;
    }
    for(int i = 0; i < N; i++){
        cin >> t;
        postorder.push_back(t);
    }

    divideAndPrintPreorder(idx, inorder, postorder, {0, N-1}, {0, N-1});    
    return 0;
}
