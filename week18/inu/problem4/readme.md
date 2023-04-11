# 문제 개요

문제 : [로봇 조립](https://www.acmicpc.net/problem/18116)

문제 분류 : 분리집합

# 문제 풀이

'I a b'인 경우에는 두 부품이 현재 같은 로봇의 부품임을 나타내지 않을 때 Union을 한다.  
Union을 할 때 합쳐지는 트리의 height도 부모에 더해줘서 전체 부품 갯수를 계산해준다.
'Q c'인 경우에는 Find(c)를 해서 height[c]를 출력한다.
