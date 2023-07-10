# 문제 개요

문제 : [알파벳](https://www.acmicpc.net/problem/1987)

문제 분류 : DFS

# 문제 풀이

처음에 BFS로 접근했다가 방문했던 칸에 다른 경로에서 접근할 수도 있기 때문에 DFS로 바꿨다.

- 지나온 알파벳들은 `checked[c - 'A'] = true`로 표시하고 count도 1 증가
- 재귀할 때마다 현재 maxLength와 count 비교해서 업데이트
