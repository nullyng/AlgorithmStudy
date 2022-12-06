# 문제 개요

문제 : [단어 변환](https://school.programmers.co.kr/learn/courses/30/lessons/43163)

문제 분류 : DFS

# 문제 풀이

1. **알파벳이 하나 차이나는 단어끼리 연결**하여 인접리스트를 만든다.
2. `begin`에서부터 깊이 우선 탐색하여 `target`에 도달하는 **최소 depth**를 구한다.
3. `target`에 도달할 수 있다면 최소 depth를 출력하고, 아니면 0을 출력한다.
