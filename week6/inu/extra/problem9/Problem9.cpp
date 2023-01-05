#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int parent[101];
int height[101];

bool compare(vector<int> c1, vector<int> c2) {
    return c1[2] < c2[2];
}

void swap(int& u, int& v) {
    int temp = u;
    u = v;
    v = temp;
}

int Find(int u, int origin) {
    if (parent[u] == u) {
        parent[origin] = u;
        return u;
    }

    return Find(parent[u], origin);
}

void Union(int u, int v) {
    if (height[u] > height[v])
        swap(u, v);

    parent[u] = v;

    if (height[u] == height[v])
        height[v]++;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    for (int i = 0; i < 100; i++) {
        parent[i] = i;
        height[i] = 1;
    }

    sort(costs.begin(), costs.end(), compare);

    for (vector<int> cost : costs) {
        int u = cost[0];
        int v = cost[1];
        int c = cost[2];

        u = Find(u, u);
        v = Find(v, v);

        if (u != v) {
            Union(u, v);
            answer += c;
        }
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<vector<int>> costs = { {0, 1, 1} ,{0, 2, 2},{1, 2, 5},{1, 3, 1},{2, 3, 8} };
    cout << solution(4, costs);
}