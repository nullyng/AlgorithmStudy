#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
int square[51][51];
long long answer;

long long get_sum(int r1, int c1, int r2, int c2) {
    long long result = 0;
    for(int i=r1; i<=r2; i++) {
        for(int j=c1; j<=c2; j++) {
            result += square[i][j];
        }
    }
    return result;
}

int main() {
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        string s;
        cin >> s;
        for(int j=0; j<M; j++) square[i][j] = s[j] - '0';
    }

    
    // 가로로 3개
    for(int i=0; i<M-2; i++) {
        for(int j=i+1; j<M-1; j++) {
            long long s1 = get_sum(0, 0, N-1, i);
            long long s2 = get_sum(0, i+1, N-1, j);
            long long s3 = get_sum(0, j+1, N-1, M-1);
            answer = max(answer, s1*s2*s3);
        }
    }
    
    // 세로로 3개
    for(int i=0; i<N-2; i++) {
        for(int j=i+1; j<N-1; j++) {
            long long s1 = get_sum(0, 0, i, M-1);
            long long s2 = get_sum(i+1, 0, j, M-1);
            long long s3 = get_sum(j+1, 0, N-1, M-1);
            answer = max(answer, s1*s2*s3);
        }
    }
    
    // 위 2개 아래 1개
    for(int i=0; i<N-1; i++) {
        for(int j=0; j<M-1; j++) {
            long long s1 = get_sum(0, 0, i, j);
            long long s2 = get_sum(0, j+1, i, M-1);
            long long s3 = get_sum(i+1, 0, N-1, M-1);
            answer = max(answer, s1*s2*s3);
        }
    }
    
    // 위 1개 아래 2개
    for(int i=0; i<N-1; i++) {
        for(int j=0; j<M-1; j++) {
            long long s1 = get_sum(0, 0, i, M-1);
            long long s2 = get_sum(i+1, 0, N-1, j);
            long long s3 = get_sum(i+1, j+1, N-1, M-1);
            answer = max(answer, s1*s2*s3);
        }
    }
    
    // 왼쪽 2개 오른쪽 1개
    for(int i=0; i<N-1; i++) {
        for(int j=0; j<M-1; j++) {
            long long s1 = get_sum(0, 0, i, j);
            long long s2 = get_sum(i+1, 0, N-1, j);
            long long s3 = get_sum(0, j+1, N-1, M-1);
            answer = max(answer, s1*s2*s3);
        }
    }
    
    // 왼쪽 1개 오른쪽 2개
    for(int i=0; i<N-1; i++) {
        for(int j=0; j<M-1; j++) {
            long long s1 = get_sum(0, 0, N-1, j);
            long long s2 = get_sum(0, j+1, i, M-1);
            long long s3 = get_sum(i+1, j+1, N-1, M-1);
            answer = max(answer, s1*s2*s3);
        }
    }
    
    cout << answer << "\n";
    return 0;
}