# 문제 개요

문제 : [평범한 배낭](https://www.acmicpc.net/problem/12865)

문제 분류 : DP

# 문제 풀이

dp[i][j] : 물건을 i개 들고 가고 무게 합이 j일 때의 가치

현재 물건의 무게가 w이고 가치가 v일 때,
0 < j <= w - 1에서의 dp[i][j]는 현재 물건을 가지고 가지 않는 경우와 같다.  
즉, dp[i][j] = dp[i - 1][j]

w <= j <= K에서의 dp[i][j]는 현재 물건을 가지고 가지 않는 경우와 현재 물건을 들고가는 경우 중 큰 값이 된다.  
즉, dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v)