# 문제 개요

문제 : [배달](https://school.programmers.co.kr/learn/courses/30/lessons/12978)

문제 분류 : 다익스트라

# 문제 풀이

먼저 road에 저장된 간선 정보를 그래프로 저장한다.  
큐에는 마을 번호와 마을까지 오기 위해 걸리는 시간을 저장한다.

1번 마을부터 탐색하면서 특정 마을에서 갈 수 있는 다른 마을까지 가기 위해 걸리는 시간을 계산해서 dist 배열에 저장된 시간을 갱신한다.

탐색이 끝나면 dist 배열 값이 K보다 같거나 작은 것의 갯수를 세서 출력한다.