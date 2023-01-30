# 문제 개요

문제 : [게임 닉네임](https://www.acmicpc.net/problem/16934)

문제 분류 : 트라이

# 문제 풀이

닉네임을 맵과 트라이에 넣어서 관리한다.

1. 맵에 없는 닉네임이면
   - 맵에 닉네임을 넣고 트라이에 넣는다.
   - 트라이를 탐색하면서 닉네임을 넣을 때 노드가 만들어지지 않은 문자가 나오면 그때까지의 접두사가 별칭이 되므로 출력하고 나머지 문자를 넣는다.
2. 맵에 있는 닉네임이면
   - 현재 닉네임에 숫자를 붙여서 출력한다.