# 문제 개요

문제 : [두 배 더하기](https://www.acmicpc.net/problem/12931)

문제 분류 : 그리디

# 문제 풀이

**B에서 A를 만든다.**  
즉, B의 모든 원소를 주어진 연산에 따라 0으로 만드는 데에 걸리는 횟수를 구한다.

1. B의 원소 중 홀수가 있다면 그 수를 1만큼 줄이는 연산을 수행한다.  
   홀수의 개수만큼 정답을 증가시킨다.
2. 모든 원소가 0인지 확인한다.
3. B의 원소를 전부 2로 나눈다.  
   정답을 1만큼 증가시킨다.
4. 모든 원소가 0인지 확인한다.

위 과정을 모든 원소가 0일 때까지 반복한다.
