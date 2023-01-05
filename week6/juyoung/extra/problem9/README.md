# 문제 개요

문제 : [섬 연결하기](https://school.programmers.co.kr/learn/courses/30/lessons/42861)

문제 분류 : 분리집합

# 문제 풀이

최소의 비용으로 모든 섬이 서로 통행 가능하도록 만들기 위해서 MST를 만들어야 한다.  
따라서 **크루스칼 알고리즘**을 사용한다.

1. `root` 배열을 자기 자신으로 초기화한다.
2. 인자로 넘어온 벡터 `cost`를 새로 선언한 벡터 `edge`에 비용, 섬 번호 순으로 push한다.
   ```cpp
   vector<tuple<int, int, int>> edge;
   for(int i=0; i<(int)costs.size(); i++) {
       edge.push_back({costs[i][2], costs[i][0], costs[i][1]});
   }
   ```
3. `edge`를 오름차순 정렬한다.
4. `edge`를 순차적으로 탐색하며 사이클을 이루지 않도록 그래프를 만든다.
   - 이때, 사이클 여부 판별을 위해 `root` 배열과 **Union-Find 알고리즘**을 사용한다.
5. 깊이 우선 탐색을 하며 연결되는 간선의 비용을 `answer`에 저장한다.
6. 연결된 간선의 수가 `n-1`개가 되면 탐색을 종료하고 `answer`를 출력한다.
   - MST의 간선 개수는 정점의 수-1개이기 때문이다.
