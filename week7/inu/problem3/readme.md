# 문제 개요

문제 : [12834 주간 미팅](https://www.acmicpc.net/problem/12834)

문제 분류 : 다익스트라

# 문제 풀이

팀원의 수만큼 다익스트라를 수행하면 된다.  
다익스트라가 끝날때마다 dist[A], dist[B]를 전체 거리에 더해주는데 갈 수 없는 경우에는 -1을 더해주면 된다.
