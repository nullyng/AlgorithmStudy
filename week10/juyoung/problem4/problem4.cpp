#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool isAvailable;

string makeBinaryString(long long n) {
    string result = "";
    
    while(n>=1) {
        result += '0' + n%2;
        n /= 2;
    }
    
    int num = 1;
    while(result.length() >= num) num *= 2;
    num -= result.length()+1;
    
    for(int i=0; i<num; i++) result += '0';
    reverse(result.begin(), result.end());
    
    return result;
}

void search(string binary, long long left, long long right, bool isZero) {
    if(left > right) return;
    
    long long mid = (left+right)/2;
        
    if(isZero && binary[mid] == '1') {
        isAvailable = false;
        return;
    }
    if(binary[mid] == '0') isZero = true;
    if(left == right) return;
    
    search(binary, left, mid-1, isZero);
    search(binary, mid+1, right, isZero);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for(int i=0; i<numbers.size(); i++) {
        // 10진수 -> 2진수
        string binary = makeBinaryString(numbers[i]);
        
        // 이진탐색으로 좌우 트리를 만들 수 있는지 확인
        isAvailable = true;
        search(binary, 0, binary.length()-1, false);
        
        if(isAvailable) answer.push_back(1);
        else answer.push_back(0);
    }

    return answer;
}