# 문제 개요

문제 : [정수 삼각형](https://school.programmers.co.kr/learn/courses/30/lessons/43105)

문제 분류 : DP

# 문제 풀이

dp[i][j] : 위에서 i번째 줄 j번째 칸의 최댓값이라 정의했을 때

- dp[i][0] = dp[i - 1][0] + triangle[i][0]
- dp[i][len] = dp[i - 1][pre] + triangle[i][len]
  - len : dp[i]의 마지막 인덱스
  - pre : dp[i - 1]의 마지막 인덱스

위 두 경우를 제외한 나머지는 dp[i][j] = triangle[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j])와 같다.  
위 과정을 반복하고 마지막 줄에서 최댓값을 찾으면 된다.
