# 문제 개요

문제 : [타일 채우기 3](https://www.acmicpc.net/problem/14852)

문제 분류 : DP

# 문제 풀이

[다른 사람 풀이](https://dlog0518.tistory.com/m/41)를 참고했다.

벽이 몇 개씩 추가될 때마다 개수에 따라 고유한 경우의 수가 있다.

- 벽 1개 추가 : 2가지
- 벽 2개 추가 : 3가지
- 벽 3개 추가 : 2가지
- 벽 4개 추가 : 2가지 ...

벽을 2개 이상 추가할 때의 고유한 경우에는 1x2 벽이 있는 경우만 포함된다.  
그렇지 않은 경우는 벽을 1개 추가하는 경우에 포함되어 있기 때문이다.

![IMG_6A00BB8EFE1D-1](https://user-images.githubusercontent.com/57346428/209794021-ba330db4-f5d9-4465-bd5e-f52d33e91d03.jpeg)

위 그림을 통해 벽을 2개 추가하는 경우를 제외하고는 전부 고유한 경우의 수가 2개인 것을 확인할 수 있다.  
이를 바탕으로 점화식을 채우면 다음과 같다.

- **`dp[i]` : 2\*`dp[i-1]` + 3\*`dp[i-2]` + 2\*(`dp[i-3]` + `dp[i-4]` + ... + `dp[1]`)**

이때 `dp[i-3]`부터 `dp[1]`까지의 합은 `sum`에 저장한다고 하면, 아래로 표현할 수 있다.

- **`dp[i]` : 2\*`dp[i-1]` + 3\*`dp[i-2]` + 2\*`sum`**

dp 배열을 초기화 한 후, 점화식에 맞게 배열을 채우면 배열의 마지막 원소가 정답이 된다.