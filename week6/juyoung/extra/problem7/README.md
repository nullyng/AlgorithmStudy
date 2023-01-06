# 문제 개요

문제 : [중량제한](https://www.acmicpc.net/problem/1939)

문제 분류 : 분리집합

# 문제 풀이

[13905 세부](https://www.acmicpc.net/problem/13905) 문제와 비슷한 문제였다.  
**크루스칼 알고리즘**을 사용하고, 사이클 판별에 **Union-Find 알고리즘**을 사용했다.

1. 간선을 입력 받는다.
   - 이때, **가중치에 -1을 곱한 값을 필두로 벡터에 push** 한다.
   - 이는 **최대로** 옮길 수 있는 금빼빼로의 수를 구해야 하기 때문이다.
2. 간선이 저장된 벡터를 오름차순 정렬한다.
3. 정렬한 벡터를 순차적으로 탐색하며 사이클을 이루지 않도록 간선을 연결한다.
   - **Union-Find 알고리즘**을 사용한다.
   - Find로 연결된 두 노드의 부모가 같은지 판별한다.
   - 부모가 같으면 해당 간선을 연결 시 사이클이 형성된다는 뜻이므로 건너뛴다.
   - 부모가 같지 않으면 해당 간선을 연결하기 위해 Union 한다.
4. 만든 그래프를 시작점에서부터 **깊이 우선 탐색**하며 이동한 간선의 가중치를 배열에 저장한다.
5. 도착점에 도달하면 저장된 가중치 중 가장 작은 값을 `answer`에 저장한다.
6. `answer`를 출력한다.