# 문제 개요

문제 : [친구 네트워크](https://www.acmicpc.net/problem/4195)

문제 분류 : 분리집합

# 문제 풀이

친구 네트워크를 형성하기 위해 입력되는 사람들을 같은 그룹으로 묶어야 한다.  
따라서 **Union-Find 알고리즘**을 사용한다.

정수가 아니라 문자열을 입력 받는 것이므로 map 자료구조를 사용했다.  
또한 같은 그룹 내의 친구 수를 구해야 하므로 Union 시 이를 계산했다.

map의 key에는 이름, value에는 {루트, 그룹의 사람 수}를 저장한다.

```cpp
map<string, pair<string, int>> m;
```

1. 이름 `A`와 `B`를 입력 받는다.
2. 각각 map에 존재하는지 확인하고, 존재하지 않는다면 value를 `{이름, 1}`로 초기화 한다.
   ```cpp
   if(m.find(A) == m.end()) m[A] = {A, 1};
   if(m.find(B) == m.end()) m[B] = {B, 1};
   ```
3. `A`와 `B`를 Union 한다.
   - 이때, 높이가 낮은 트리(사람이 적은 그룹)를 높이가 높은 트리(사람이 많은 그룹)에 붙인다.
   - 높이가 낮은 트리의 depth를 높이가 높은 트리의 depth에 더한다.
   - 즉, 사람이 적은 그룹의 사람 수를 사람이 많은 그룹의 사람 수에 더한다.
     ```cpp
     if(m[A].second < m[B].second) {
       m[A].first = m[B].first;
       m[B].second += m[A].second;
     }
     else {
       m[B].first = m[A].first;
       m[A].second += m[B].second;
     }
     ```
4. `A`의 루트를 Find 하고, 그 값을 map에서 찾아 해당 그룹의 사람 수를 출력한다.
