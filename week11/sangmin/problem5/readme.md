# 문제 개요

문제 : [다리 만들기](https://www.acmicpc.net/problem/2146)

문제 분류 : 그래프 이론, 넓이 우선 탐색

# 문제 풀이

bfs를 통해 노드들에게 각자 번호를 부여한다. 이 때, 같은 번호의 노드는 같은 땅에 속해있는 노드이다.

그 후 노드들간의 번호가 다르면 거리를 구해준다.

거리를 구해준 후 가장 작은 거리가 정답이 된다.