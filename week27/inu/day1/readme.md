# 문제 개요

문제 : [백도어](https://www.acmicpc.net/problem/17396)

문제 분류 : 다익스트라

# 문제 풀이

그래프의 최단 경로이고 음수 간선이 없기 때문에 다익스트라로 해결했다.  
우선순위 큐에 누적 시간까지 저장해서 현재 정점(v)의 갱신된 최단 거리(dist[v])가 누적 시간보다 작다면 탐색하지 않도록 해서 시간을 줄이도록 한다.
