# 문제 개요

문제 : [운동](https://www.acmicpc.net/problem/1956)

문제 분류 : 플로이드 와샬

# 문제 풀이

graph[i][i]의 값을 INF로 두고 플로이드 알고리즘을 실행했을 때 INF가 아닌 graph[i][i]의 값들 중에서 가장 작은 값이 답이 된다.

또는, graph[i][i]는 0으로 두고 플로이드 알고리즘 실행 후에 graph[i][k] + graph[k][i] 값들 중에서 가장 작은 값을 찾아도 된다.
