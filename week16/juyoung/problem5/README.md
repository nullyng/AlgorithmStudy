# 문제 개요

문제 : [평범한 배낭](https://www.acmicpc.net/problem/12865)

문제 분류 : DP

# 문제 풀이

`dp[i][j]`에서 i는 물건, j는 현재 배낭의 무게를 의미한다.

- 현재 물건의 무게보다 `j`가 작으면 현재 물건을 포함할 수 없으므로 이전 값을 그대로 쓴다.
  ```cpp
  dp[i][j] = dp[i-1][j];
  ```
- 현재 물건의 무게보다 `j`가 크거나 같으면 max(이전 값, 현재 물건의 무게를 뺀 이전 값+현재 물건의 가치)
  ```cpp
  dp[i][j] = max(dp[i-1][j], dp[i-1][j-W[i]]+V[i]);
  ```

![IMG_7EC3349AF5A2-1](https://user-images.githubusercontent.com/57346428/227515534-9a796234-38e9-4e35-bc9b-7b9cd05309d5.jpeg)
