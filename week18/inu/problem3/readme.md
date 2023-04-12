# 문제 개요

문제 : [피리 부는 사나이](https://www.acmicpc.net/problem/16724)

문제 분류 : 분리 집합, DFS

# 문제 풀이

아직 방문하지 않은 곳에서 시작해서 화살표대로 탐색을 한다.  
방문한 곳은 1로 표시하면서 가다가 visited가 1인 곳을 만나면 사이클이 생긴 곳이므로 result++을 한다.  
DFS가 끝나면 visited를 2로 표시해서 다른 사이클을 찾을 때 고려하지 않도록 한다.  
(이걸 분리집합으로 어케 푼담..?)