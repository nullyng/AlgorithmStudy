# 문제 개요

문제: [동전 2](https://www.acmicpc.net/problem/2294)

문제 분류: DP

# 문제 풀이

- **`dp[i]` : i원을 만드는 데 드는 동전의 최소 개수**

충분히 큰 수로 초기화된 `dp` 배열에서 입력받은 동전에 해당하는 `dp`값을 1로 초기화한다.

이후 모든 동전에 대해 그 동전의 값부터 `k`까지 `dp` 배열을 채우는데,  
`현재 값-동전의 값`에 해당하는 `dp`값에 1을 더한 값과 현재의 `dp`값을 비교하여 더 작은 값을 저장한다.
