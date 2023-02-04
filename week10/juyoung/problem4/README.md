# 문제 개요

문제 : [표현 가능한 이진트리](https://school.programmers.co.kr/learn/courses/30/lessons/150367)

문제 분류 : 2023 KAKAO BLIND RECRUITMENT

# 문제 풀이

1. 십진수를 이진수로 바꾼다.
   - 이때 2의 거듭제곱-1 자리를 맞춰준다.
   - ex) `110010001`(9자리) → `000000110010001`(15자리)
2. 이진탐색으로 각 서브트리의 루트를 방문하며 해당 서브트리를 만들 수 있는지 확인한다.
   - **⭐️어떤 노드가 1일 때, 해당 노드의 부모 노드 중 하나라도 0인 값이 있으면 해당 수는 하나의 이진트리로 표현할 수 없다.⭐️**
     - 재귀적으로 호출한 부모 노드 중 하나라도 0인 값이 있었다면, `isZero`에 true를 저장하고 재귀함수의 인자로 보낸다.
     - `isZero`가 true이고 현재 노드가 1이면 `isAvailable`에 false를 저장한다.
   - 리프 노드가 아닌 경우에 좌우 트리에 대해 재귀적으로 탐색한다.
     - `low`와 `high`가 같은 경우가 리프 노드에 해당한다.
3. `isAvailable`가 true이면 `answer`에 1을, false이면 0을 push한다.

위 풀이로 코드를 작성하고 제출했는데 테케 4번부터 끝까지 다 실패라고 떴다.  
뭐가 문제인지 모르겠어서 중간중간 출력해봤더니 아래 코드에 문제가 있었다.

```cpp
int num = 1;
while(result.length() >= num) num *= 2;
num--;

for(int i=0; i<num-result.length(); i++) result += '0';
reverse(result.begin(), result.end());
```

위에서도 예시를 들었던 `110010001`으로 테스트 해보니까, 6번 돌아야 할 for문이 3번만 돌았다.  
`num`은 15, `result.length()`는 9인 것도 출력으로 확인했는데 왜일까...

그래서 아래처럼 고쳤더니 성공이 떴다.  
하.. 시간 낭비 😢

```cpp
int num = 1;
while(result.length() >= num) num *= 2;
num -= result.length()+1;

for(int i=0; i<num; i++) result += '0';
reverse(result.begin(), result.end());
```
