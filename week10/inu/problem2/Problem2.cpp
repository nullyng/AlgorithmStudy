#include <string>
#include <vector>
#define N 100000

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    int d_sum[N];
    int p_sum[N];

    d_sum[n - 1] = deliveries[n - 1];
    p_sum[n - 1] = pickups[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        d_sum[i] = d_sum[i + 1] + deliveries[i];
        p_sum[i] = p_sum[i + 1] + pickups[i];
    }

    long long answer = 0;
    int capSum = 0;

    for (int i = n - 1; i >= 0; i--) {
        int maxBox = max(d_sum[i], p_sum[i]);

        if (maxBox > capSum) {
            int visit = (maxBox - capSum) / cap;

            if (maxBox % cap) visit++;

            answer += (i + 1) * visit;
            capSum += visit * cap;
        }
    }
    
    return answer * 2;
}

int main() {
    int cap = 4;
    int n = 5;
    vector<int> deliveries = { 1, 0, 3, 1, 2 };
    vector<int> pickups = { 0, 3, 0, 4, 0 };

    long long result = solution(cap, n, deliveries, pickups);

    return 0;
}

//int cap = 2;
//int n = 7;
//vector<int> deliveries = { 1, 0, 2, 0, 1, 0, 2 };
//vector<int> pickups = { 0, 2, 0, 1, 0, 2, 0 };

//int cap = 4;
//int n = 5; 
//vector<int> deliveries = { 1, 0, 3, 1, 2 };
//vector<int> pickups = { 0, 3, 0, 4, 0 };