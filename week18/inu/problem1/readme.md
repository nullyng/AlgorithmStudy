# 문제 개요

문제 : [여러분의 다리가 되어 드리겠습니다!](https://www.acmicpc.net/problem/17352)

문제 분류 : 분리집합

# 문제 풀이

주어진 다리들을 집합으로 만들고 이어져있지 않은 2곳을 찾아 출력하면 된다.  
여러 개 중에 아무거나 출력하면 되기 때문에 parent[i] == i인 것을 2개 찾아 출력했다.
