# 문제 개요

문제 : [공통 부분 문자열](https://www.acmicpc.net/problem/5582)

문제 분류 : DP

# 문제 풀이

두 문자열 탐색 시 각각의 인덱스 `i`, `j`에 대해  
`s1[i]==s2[j]`인 경우 `dp[i][j]`에 `dp[i-1][j-1]+1`을 대입한다.

`dp` 배열의 원소 중 가장 큰 값이 정답이 된다.

![IMG_FF2178D40FEF-1](https://user-images.githubusercontent.com/57346428/228206665-c6234a9f-9c13-4372-84c3-3cb84a20b274.jpeg)
