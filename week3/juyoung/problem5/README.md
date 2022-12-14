# 문제 개요

문제 : [치킨 배달](https://www.acmicpc.net/problem/15686)

문제 분류 : 백트래킹

# 문제 풀이

1. 치킨집 중 `M`개를 뽑는 모든 **조합**을 구한다.
2. 모든 조합에 대해 각 집의 치킨 거리의 합을 구한다.
3. 이 중 최솟값을 찾는다.

집과 치킨집의 위치는 각각 서로 다른 벡터에 저장한다.  
배열 `selected`에 치킨집 중 `M`개를 뽑는 조합을 저장한다.

`makeComb()` 함수를 재귀적으로 호출하는데, 이때 파라미터로는

- 현재까지 뽑은 치킨집의 수 `cnt`
- 뽑은 치킨집의 다음 치킨집부터 탐색하기 위한 `idx`

위 두 가지를 넘긴다.

`idx`번 치킨집부터 마지막 치킨집까지 탐색하며, `selected[cnt]`에 뽑은 치킨집을 저장한다.  
그리고 `makeComb()` 함수를 재귀 호출한다.  
만약 `cnt`가 `M`과 같아진다면 만들어진 조합을 바탕으로 모든 집의 치킨 거리를 구한다.  
모든 조합에 대해 이를 구하고, 가장 최솟값을 저장하여 출력한다.
