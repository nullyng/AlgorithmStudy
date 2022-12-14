# 문제 개요

문제 : [두 동전](https://www.acmicpc.net/problem/16197)

문제 분류 : bfs

# 문제 풀이

큐에는 두 동전의 위치와 버튼을 누른 횟수를 저장하는 자료구조를 저장한다.  
버튼을 누르면 두 동전의 상태는 3가지 중 하나가 된다.

1. 동전이 둘 다 떨어졌을 때
   - 다음 방향에 대한 버튼을 누른다.
2. 둘 중 하나만 떨어졌을 때
   - 현재의 최소 횟수와 비교해서 값을 바꾼다.
3. 둘 다 안 떨어졌을 때
   - 둘 다 벽에 부딪히면, 즉 두 동전의 위치가 바뀌지 않으면 큐에 넣지 않는다.
   - 둘 중 하나만 벽에 부딪히면, 부딪힌 동전의 좌표를 원래 좌표로 되돌린다.
   - 첫 번째 동전의 위치를 (x1, y1)이라 하고 두 번째 동전의 위치를 (x2, y2)라 했을 때, `visited[x1][y1][x2][y2]`가 false고 횟수 + 1이 10 미만이면 큐에 넣는다.
