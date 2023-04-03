# 문제 개요

문제 : [가장 긴 바이토닉 부분 수열](https://www.acmicpc.net/problem/11054)

문제 분류 : DP

# 문제 풀이

1. 수열 A의 **앞에서부터** LIS 길이를 구해서 `dp1` 배열에 저장한다.
2. 수열 A의 **뒤에서부터** LIS 길이를 구해서 `dp2` 배열에 저장한다.
3. 1부터 `N`까지 차례대로 탐색하며 가장 큰 `dp1[i]+dp2[i]-1` 값을 찾아 출력한다.