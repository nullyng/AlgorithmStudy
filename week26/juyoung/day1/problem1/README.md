# 문제 개요

문제: [피보나치 수 7](https://www.acmicpc.net/problem/15624)

문제 분류: 수학

# 문제 풀이

`fibo` 배열을 아래와 같이 초기화 한다.

- `fibo[0]` = 0
- `fibo[1]` = 1

이후 `n`번 인덱스까지 `fibo` 배열을 채운다.

```cpp
fibo[i] = (fibo[i-1] + fibo[i-2]) % 1000000007;
```
