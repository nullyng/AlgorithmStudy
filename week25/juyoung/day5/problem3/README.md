# 문제 개요

문제: [팰린드롬 만들기](https://www.acmicpc.net/problem/1695)

문제 분류: DP, 재귀

# 문제 풀이

[다른 사람 풀이](https://mapocodingpark.blogspot.com/2020/07/1695.html)를 참고했다.

- `dp[i][j]`: `i`와 `j`를 양끝으로 하는 팰린드롬을 만들기 위해 추가해야 하는 수의 최소 개수

주어진 입력 배열의 양끝에서부터 안쪽 방향으로 비교해나가는데, 왼쪽을 `l`, 오른쪽을 `r`이라고 했을 때 다음을 수행한다.

1. `l`과 `r`이 같다면 안쪽으로 한 칸 이동해서 비교한다.
2. 다르다면 한 쪽만 옮겼을 때 더 작은 값이 무엇인지 구한다.

```cpp
if(arr[l] == arr[r]) cnt = pal(l + 1, r - 1);
else cnt = min(pal(l, r - 1), pal(l + 1, r)) + 1;
```

이렇게 재귀적으로 함수를 호출하며 `dp[l][r]`에 `cnt`를 저장한다. 또한 `dp`는 초반에 모든 원소를 -1로 초기화하는데, 시간 초과를 피하기 위해 함수 호출 시 `dp[l][r]` 값이 이미 -1이 아니라면 그 값을 바로 반환한다.
