# 문제 개요

문제 : [동전 1](https://www.acmicpc.net/problem/2293)

문제 분류 : DP

# 문제 풀이

i번째 동전 coin[i]까지 사용했을 때 가능한 가치를 업데이트 한다.
dp[k]를 k원을 만들기 위한 경우의 수라고 하자.  
k원을 만들기 위해 coin[i]를 사용하면 가능한 경우의 수는 dp[k - coin[i]]가 된다.  
따라서 i를 n까지 증가시키면서 dp[k]에 dp[k - coin[i]]를 더해주며 갱신하면 된다.
