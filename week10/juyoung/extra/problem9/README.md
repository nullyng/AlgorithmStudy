# 문제 개요

문제 : [나무 자르기](https://www.acmicpc.net/problem/2805)

문제 분류 : 이분탐색

# 문제 풀이

랜선 자르기 문제와 비슷하게 풀이했다.

나무의 높이를 입력받을 떄 가장 큰 높이를 따로 저장해두고 이 값을 이분탐색의 초기 `high` 값으로 사용한다.  
나무의 높이에서 `mid`를 뺀 값, 즉 자른 나무들의 높이의 합을 저장하는 `sum`이

- `M`개보다 크거나 같으면
  - 현재 정답과 `mid` 중 더 큰 값으로 정답을 업데이트한다.
  - 나무를 필요한 만큼만 가지고 가려면 가능한 더 큰 값이 있는지 찾아야 한다.
  - 따라서 `low`에 `mid+1`을 저장한다.
- `N`개보다 작으면
  - 자르는 길이를 더 작게 하여 `sum` 값을 늘려야하므로 `mid`의 값을 줄여야 한다.
  - 따라서 `high`에 `mid-1`을 저장한다.

나무의 높이가 최대 1,000,000,000이므로 자른 나무들의 높이를 저장하는 `sum`은 long long 타입으로 선언해야 한다.
