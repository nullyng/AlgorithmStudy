# 문제 개요

문제 : [5904 Moo 게임](https://www.acmicpc.net/problem/5904)

문제 분류 : 분할정복

# 문제 풀이

1. 처음으로 N보다 커지는 S(k)와 k를 찾는다.
2. S(k) = S(k - 1) + (1 + k + 2) + S(k - 1)이다.
   - 이 때, 나누어지는 세 부분을 ①, ②, ③이라 하고 N이 세 부분 중 어디에 속하는지 찾는다.
   - ① : 1 <= N <= S(k - 1)
   - ② : S(k - 1) < N <= S(k - 1) + (k + 3)
   - ③ : N > S(k - 1) + (k + 3)
3. ②이면 N - S(k - 1)을 구해서 1이면 'm'을 반환하고 아니면 'o'를 반환
4. ①, ③ 이면 다시 재귀 함수를 호출한다.
5. 함수 파라미터 중 k가 0일 때, N이 1이면 'm'을 반환하고 아니면 'o'를 반환한다.
