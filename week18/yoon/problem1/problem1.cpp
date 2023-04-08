#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, a, b;
int parent[300001];

int fin(int a) {
    if (a == parent[a])
        return a;
    return parent[a] = fin(parent[a]);
}

void merge(int a, int b) {
    int pa = fin(a);
    int pb = fin(b);
    parent[pa] = pb;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
        parent[i] = i;

    for (int i = 0; i < N - 2; i++) {
        cin >> a >> b;
        merge(a, b);
    }

    int f = fin(1);
    for (int i = 2; i <= N; i++) {
        if (fin(i) != f) {
            cout << 1 << " " << i;
            break;
        }
    }

    return 0;
}
