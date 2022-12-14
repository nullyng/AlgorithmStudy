# 문제 개요

문제 : [전깃줄](https://www.acmicpc.net/problem/2565)

문제 분류 : DP

# 문제 풀이

**최장 증가 부분 수열(LIS)** 알고리즘을 사용한다.

A 위치를 기준으로 전깃줄을 정렬했을 때, 각 전깃줄의 B 위치의 LIS의 길이를 구하고 이를 전깃줄의 개수에서 빼면 정답이 된다.  
여기서 LIS란 겹치지 않는 전깃줄의 최대 개수이기 때문이다.

즉, 이 문제에서 `dp[i]`는 다음과 같이 정의할 수 있다.

- **`dp[i]` : i번째 원소를 포함한 최장 증가 부분 수열의 길이**

문제는 아래의 순서로 풀이했다.

1. `dp` 배열을 1로 초기화 한다.
   - LIS에 자신만 포함될 떄는 길이가 1이기 때문이다.
2. 전깃줄을 A 위치를 기준으로 오름차순 정렬한다.
3. LIS의 길이를 `dp` 배열에 기록한다.
   1. 전깃줄을 차례대로 탐색하며 이전 전깃줄과 B 위치를 비교한다.
   2. 현재 전깃줄(`i`)의 B 위치가 이전 전깃줄(`j`)의 B 위치보다 크다면 이전 전깃줄은 증가 수열에 포함된다.
      - 현재 전깃줄의 LIS의 길이 `dp[i]`와 이전 전깃줄의 LIS에 1만큼 더한 `dp[j]+1` 중 더 큰 값을 `dp[i]`에 대입한다.
   3. `answer`과 `dp[i]` 중 더 큰 값을 `answer`에 대입한다.
4. 전깃줄의 개수 `N`에서 `answer`을 뺀 값을 출력한다.
   - `answer`에는 겹치지 않는 전깃줄의 최대 개수가 저장되어 있다.
   - 따라서 제거해야 할 최소 전깃줄의 개수를 구하려면 `N`에서 `answer`를 빼야한다.
