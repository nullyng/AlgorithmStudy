# 문제 개요

문제 : [1865 웜홀](https://www.acmicpc.net/problem/1865)

문제 분류 : 벨만 포드

# 문제 풀이

참고: https://www.acmicpc.net/board/view/72995

시작점이 당연히 1이라고 생각하고 풀었다가 틀렸다.  
시작점이 어디라는 언급이 없기 때문에 모든 정점에 도달 가능하다고 생각해야 한다.  
따라서 거리를 저장하는 배열을 INF가 아닌 0으로 초기화해야 한다.  
이렇게 해서 벨만 포드를 적용하고 음수 사이클이 있으면 YES를 출력하면 된다.