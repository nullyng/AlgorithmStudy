#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, a, b;
    cin >> N;

    map<int, int> m;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        m[a]++;
        m[b]--;
    }

    int prefixSum = 0, max = 0;
    for(auto entry : m){
        prefixSum += entry.second;
        if(max < prefixSum) max = prefixSum;
    }

    cout << max;
return 0;
}
