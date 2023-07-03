# 문제 개요

문제 : [파이프 옮기기 1](https://www.acmicpc.net/problem/17070)

문제 분류 : BFS

# 문제 풀이

BFS 시 queue에 y, x, 파이프 방향에 대한 정보를 함께 push한다.  
그래서 꺼낸 값에서 위치와 파이프 방향에 따라 아래와 같이 처리한다.

- 현재 위치에서 세 방향에 대해 탐색한다. (오른쪽, 대각선, 아래)
  - 만약 파이프 방향이 가로라면 아래는 탐색하지 않는다.
  - 만약 파이프 방향이 세로라면 오른쪽은 탐색하지 않는다.
- 새로 탐색한 곳이 벽이 아니라면 queue에 위치와 탐색한 방향(파이프 방향)을 push한다.
  - 새로 탐색한 곳이 대각선 방향이라면 위, 왼쪽도 추가로 탐색하여 벽인지 확인한다.
  - 새로 탐색한 곳이 (N, N)이라면 push하지 않고 정답을 카운트한다.

1년 전에도 풀었던 문제인데 확인해보니까 그때는 DFS로 문제를 풀이했었다.  
BFS보다 DFS로 풀었을 때 메모리와 시간이 훨씬 적게 들었다...