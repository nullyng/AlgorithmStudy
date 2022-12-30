# 문제 개요

문제 : [14852 타일 채우기3](https://www.acmicpc.net/problem/14852)

문제 분류 : DP

# 문제 풀이

N의 길이마다 다르게 나오는 고유한 타일 배치가 있다.  
N = 2인 경우는 제외하고 모두 2가지씩 있다는 것을 알 수 있다.

<img width="500" src="https://user-images.githubusercontent.com/55791128/210059488-52582cc0-4993-4964-850a-ae00d8339cd6.jpg" />

따라서, dp[N]을 다음과 같이 구할 수 있다.

<img width="500" src="https://user-images.githubusercontent.com/55791128/210060299-724f5ad4-78cf-476d-aca2-dda99fe3840b.jpg" />

N - 2 이후로는 모두 2가지씩 있기 때문에 2로 묶어주면 dp[N - 3] + dp [N - 4] + ... + dp[0]이 된다.  
0 ~ N인 모든 경우에 대해서 계산하면 O(N^2)만큼의 시간이 걸리기 때문에 dp 배열을 2차원 배열로 나누어서 이전 계산 결과를 저장하도록 한다.

dp[1][n] = dp[N - 3] + dp[N - 4] + ... + dp[0]이 되고 이를 나타내면  
dp[1][n] = dp[N - 3] + (dp[N - 4] + dp[N - 5] + ... + dp[0]) = dp[0][n - 3] + dp[1][n - 1]이 된다.
