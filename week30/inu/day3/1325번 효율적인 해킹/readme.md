# 문제 개요

문제 : [효율적인 해킹](https://www.acmicpc.net/problem/1325)

문제 분류 : DFS, BFS

# 문제 풀이

'A가 B를 신뢰한다'에서 B를 해킹하면 A도 해킹할 수 있기 때문에 B->A인 방향 그래프를 만든다.  
그리고 DFS나 BFS로 탐색을 하면서 해킹 가능한 컴퓨터수가 최대인 노드를 찾는다.
