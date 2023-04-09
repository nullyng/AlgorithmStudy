# 문제 개요

문제 : [적의 적](https://www.acmicpc.net/problem/12893)

문제 분류 : 분리집합

# 문제 풀이

[다른 사람 풀이](https://dparkjm.com/ps/boj-12893)를 참고했다.

동지 그룹을 저장하는 배열과 적 그룹을 저장하는 배열을 각각 따로 선언한다.

- 입력된 `A`와 `B`가 같은 동지 그룹에 있다면 이론은 성립하지 않는다.  
  즉, `A`와 `B`를 각각 Find 한 값이 같다면 0을 출력하고 프로그램을 종료한다.
- 그렇지 않으면 `A`의 적 그룹에 `B`를 합치고, `B`의 적 그룹에 `A`를 합친다.  
  `A`의 적 그룹이 이미 존재한다면 그 그룹에 `B`를 합치고(Union),  
  그렇지 않다면 `A`의 적 그룹에 `B` 그룹을 대입한다.  
  `B`도 마찬가지로 수행한다.

  ```cpp
  int eofa = enemy[A];
  int eofb = enemy[B];

  if(eofa) Union(eofa, B);
  else enemy[A] = B;

  if(eofb) Union(eofb, A);
  else enemy[B] = A;
  ```

- 이론이 성립하면 1을 출력하고 프로그램을 종료한다.
