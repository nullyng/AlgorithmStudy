#include <iostream>
#include <algorithm>
using ll = long long;
using namespace std;

int side3[8][3] = {{0,1,2}, {0,1,3}, {0,3,4}, {0,2,4}, {1,2,5}, {1,3,5}, {2,4,5}, {3,4,5}};
int side2[12][2] = {{0,1}, {0,2}, {0,3}, {0,4}, {1,2}, {1,3}, {1,5}, {2,4}, {2,5}, {3,4}, {3,5}, {4,5}};

int main() {
    ll N;
    int dice[6];
    
    cin >> N;
    
    int side1_min = 999;
    int side1_max = 0;
    int dice_sum = 0;
    for(int i=0; i<6; i++) {
        cin >> dice[i];
        side1_min = min(side1_min, dice[i]);
        side1_max = max(side1_max, dice[i]);
        dice_sum += dice[i];
    }
    
    // 3면의 합이 최소인 값을 구하기
    int side3_min_sum = 999;
    for(int i=0; i<8; i++) {
        int sum = 0;
        for(int j=0; j<3; j++) {
            sum += dice[side3[i][j]];
        }
        side3_min_sum = min(side3_min_sum, sum);
    }
    
    // 2면의 합이 최소인 값을 구하기
    int side2_min_sum = 999;
    for(int i=0; i<12; i++) {
        int sum = 0;
        for(int j=0; j<2; j++) {
            sum += dice[side2[i][j]];
        }
        side2_min_sum = min(side2_min_sum, sum);
    }
    
    // 계산
    ll answer = 0;
    
    if(N == 1) cout << dice_sum - side1_max << "\n";
    else {
        answer += 4 * side3_min_sum;
        answer += ((2*N-3)*4) * side2_min_sum; // (N-2)*4 + (N-1)*4
        answer += ((N-2)*(N-2)+(N-2)*(N-1)*4) * side1_min;
        cout << answer << "\n";
    }
    
    return 0;
}