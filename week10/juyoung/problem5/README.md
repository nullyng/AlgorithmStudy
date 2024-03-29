# 문제 개요

문제 : [표 병합](https://school.programmers.co.kr/learn/courses/30/lessons/150366)

문제 분류 : 2023 KAKAO BLIND RECRUITMENT

# 문제 풀이

Union-Find 알고리즘을 통해 풀었다.  
초기에 `table[i][j]`은 모두 `"EMPTY"`로, `root[i][j]`는 {`i`, `j`}로 초기화한다.

각 셀에 접근할 때는 병합되었을 가능성을 생각하여 **무조건 병합된 셀 중에서 루트 셀에 접근**하도록 했다.  
즉, 모든 연산 시 병합된 셀의 루트 셀에 접근한다.  
(병합이 안 된 셀은 자기자신이 루트 셀이다.)

## 📌 UPDATE

### 1. (`r`, `c`) 위치의 셀을 `value`로 업데이트

각 셀에 접근할 때는 해당 셀의 루트 셀에 접근하므로, 업데이트 또한 루트 셀에 해당하는 셀만 해준다.  
따라서 Find 함수로 찾은 루트 셀에 해당하는 위치의 값을 업데이트 한다.

### 2. `value1`을 가진 셀의 값을 `value2`로 업데이트

이 경우, 이미 값을 가지고 있는 셀의 값을 변경하는 것이다.  
그런데 위 1번에 해당하는 업데이트에서는 "루트 셀에 해당하는 셀에만 값을 업데이트" 했다.

따라서 Find 함수로 루트 셀을 찾을 필요 없이!  
표를 순회하며 `table[i][j]`의 값이 `value1`과 같으면 `value2`로 업데이트 하면 된다.

## 📌 MERGE

병합하려는 각 셀의 루트 셀을 찾는다.  
이때 각 루트 셀이 같은 셀이라면, 이미 병합된 것이므로 retun 한다.

{`r1`, `c1`}에 해당하는 루트 셀이 {`px`, `py`}이고  
{`r2`, `c2`}에 해당하는 루트 셀이 {`cx`, `cy`}일 때  
우선 `value`에 `table[px][py]`에 해당하는 값을 저장한다.

만약 두 루트 셀에 해당하는 위치의 값이 둘 다 빈 값(`"EMPTY"`)이 아니면,  
병합된 셀은 {`r1`, `c1`}에 해당하는 값을 갖게 되기 때문이다.

그런데 `table[px][py]`가 빈 값이고, `table[cx][cy]`가 값을 가지고 있다면  
`value`를 `table[cx][cy]`로 업데이트 한다.

표를 순회하며 각 셀의 루트가 {`cx`, `cy`}와 동일한 셀을 찾아서
루트 셀을 {`px`, `py`}로 업데이트 하고, 해당 셀의 값을 빈 값으로 업데이트 한다.

마지막으로 `table[px][py]`의 값을 `value`로 업데이트 한다.

## 📌 UNMERGE

병합을 해제하려는 셀과 같은 루트를 가진 셀들을 찾아야 한다.

Find 함수를 통해 같은 루트를 가진 셀들을 찾고, 해당하는 셀의 루트 셀을 자기 자신으로 바꾼다.  
또한 해당 셀의 값을 빈 값으로 업데이트 한다.

이때 루트가 같은 셀들을 배열에 저장하고, 모두 찾은 후 배열을 순회하며 병합을 해제해도 된다.  
하지만 나는 문제에 최적화된 Find 함수를 적용하여 모든 셀의 `root`에 "최상위" 루트 셀을 저장했기 때문에  
굳이 그렇게 하지 않아도 중간에 Find 함수가 끊길 걱정은 없다.

## 📌 PRINT

출력하려는 셀의 루트 셀을 찾은 후, 루트 셀에 해당하는 위치의 값을 `answer`에 push한다.

## 💧 시간 낭비했던 이유

문제 자체는 위 알고리즘으로 빠르게 해결했는데, 테스트케이스 5번 이후로 전부 실패가 떴다.  
아무리 코드를 봐도 잘못된 게 없길래 다른 사람들 코드도 봤는데 다들 나랑 풀이가 똑같았다...

이후 2시간을 넘게 삽질했는데 알고보니까 내가 split한 문자열에서  
행, 열에 해당하는 `r`, `c`가 무조건 한 자리 숫자일 거라고 착각한 게 문제였다.

```cpp
int r = cmd[1][0] + '0';
int c = cmd[2][0] + '0';

update(r, c, cmd[3]);
```

그래서 `stoi` 함수를 사용하도록 바꿨더니 통과되었다...  
역대급 시간 낭비였던 것 같다...^^
