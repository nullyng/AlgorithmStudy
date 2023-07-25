# 문제 개요

문제 : [플로이드](https://www.acmicpc.net/problem/11404)

문제 분류 : 플로이드 와샬

# 문제 풀이

1. 2차원 배열 `dist`를 충분히 큰 수로 초기화한다.
2. 플로이드 와샬 알고리즘으로 `dist` 배열을 채운다.
3. `dist` 배열 값이 충분히 큰 수이면 0, 아니면 값 그대로를 출력한다.