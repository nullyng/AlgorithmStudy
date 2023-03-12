#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int initSeg(vector<int>& seg, vector<int>& map, int root, int start, int end) {
    if(start == end) return seg[root] = map[start];
    int mid = (start + end) / 2;
    return seg[root] = max(initSeg(seg, map, root * 2, start, mid), initSeg(seg, map, root * 2 + 1, mid + 1, end));
}

int find(vector<int>& seg, vector<int>& map, int start, int end, int root, int left, int right) {
    if(start > right || end < left) return 0;
    if(left <= start && end <= right) return seg[root];

    int mid = (start + end) / 2;
    return max(find(seg, map, start, mid, root * 2, left, right), find(seg, map, mid + 1, end, root * 2 + 1, left, right));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int H, W, res = 0;
    cin >> H >> W;
    vector<int> map(W + 1, 0);
    vector<int> seg(W * 4, 0);
    for(int i = 1; i <= W; i++) cin >> map[i];
    initSeg(seg, map, 1, 1, W);
    for(int i = 2; i < W; i++) res += max(min(find(seg, map, 1, W, 1, 1, i - 1), find(seg, map, 1, W, 1, i + 1, W)) - map[i], 0);
    cout << res;
    return 0;
}
