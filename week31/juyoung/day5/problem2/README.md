# 문제 개요

문제: [문제 추천 시스템 Version 1](https://www.acmicpc.net/problem/21939)

문제 분류: 자료구조

# 문제 풀이

[다른 사람 풀이](https://comdolidol-i.tistory.com/276)를 참고했다.

multiset이라는 자료구조를 사용했는데, multiset은 값을 삽입하면 자동으로 작은 수부터 정렬해서 삽입하며 `begin()`과 `end()`를 통해 set의 양끝에 접근할 수 있다.

또한 map에 문제 번호와 난이도를 저장하여 solved 시 문제 번호를 제거할 때 사용한다.

- **recommend** 시
  - `x`가 1인 경우: multiset의 마지막 값을 출력한다.
    ```cpp
    prev(ms.end())->second
    ```
  - `x`가 -1인 경우: multiset의 첫 번째 값을 출력한다.
    ```cpp
    ms.begin()->second
    ```
- **add** 시 multiset에 `{난이도, 문제 번호}`를 삽입한다.
- **solved** 시 map에서 문제 번호의 난이도를 찾아 multiset의 해당하는 난이도를 key로 가진 값을 삭제한다.
