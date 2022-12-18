# 문제 개요

문제 : [수 찾기](https://www.acmicpc.net/problem/1920)

문제 분류 : 이분탐색

# 문제 풀이

1. N개의 정수 A[1], A[2], ..., A[N]을 입력 받은 후 이를 **정렬**한다.
2. M개의 수들에 대해 각각 **이분탐색**을 진행한다.

이분탐색 시 `low`를 0으로, `high`를 N-1로 설정한 뒤 `low`가 `high`보다 작거나 같은 동안 아래를 수행한다.

1. `mid = (low+high)/2`
2. `A[mid]`와 입력을 비교한다.
   - `A[mid]`가 입력과 같다면 불리언 변수 `isThere`을 true로 바꾸고 break
   - `A[mid]`가 입력보다 크다면 `low = mid + 1`
   - `A[mid]`가 입력보다 작다면 `high = mid - 1`
3. `isThere` 값에 따라 1이나 0을 출력한다.

### :mag_right: 시간 초과 이유

cin과 cout은 표준입출력 함수인 scanf와 prinf에 비해 많이 느리기 때문이었다.  
입력이 엄청 많은 경우에만 아래 코드를 썼었는데 그냥 웬만한 코드에는 다 써야겠다!

```cpp
cin.tie(NULL); cout.tie(NULL);
ios_base::sync_with_stdio(false);
```
