# 문제 개요

문제: [학부 연구생 민상](https://www.acmicpc.net/problem/21922)

문제 분류: DFS

# 문제 풀이

모든 에어컨에 대해 방향별로 에어컨 바람이 오는 자리를 구한다.

`dfs` 함수의 파라미터로 현재 위치와 방향을 넘기고, 현재 위치의 물건에 따라 방향을 변경하여 새로운 위치와 방향으로 다시 `dfs` 함수를 호출한다. 이때 3차원 `visited` 배열에 각 방향별 방문 여부를 기록한다.

마지막으로 `visited` 배열을 탐색하여 방문한 자리의 개수를 카운트하여 출력하면 정답이 된다.