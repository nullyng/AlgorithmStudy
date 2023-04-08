#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> parent(1000001);
vector<int> num(1000001, 1);

int N;

int find(int a) {
    if (a == parent[a])
        return a;
    return parent[a] = find(parent[a]);
}

bool check(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa == pb)
        return false;
    return true;
}

void merge(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    parent[pa] = pb;
    num[pb] += num[pa];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char c;
    int a, b;

    cin >> N;

    for (int i = 1; i <= 1000000; i++)
        parent[i] = i;

    while (N--) {
        cin >> c >> a;
        if (c == 'I') {
            cin >> b;
            if (check(a, b)) {
                merge(a, b);
            }
        } else {
            int pa = find(a);
            cout << num[pa] << '\n';
        }
    }

    return 0;
}
