# 문제 개요

문제 : [괄호 제거](https://www.acmicpc.net/problem/2800)

문제 분류 : 문자열, 스택

# 문제 풀이

1. 괄호쌍의 위치를 파악하여 벡터에 저장한다.
2. 벡터에서 제거할 괄호의 부분집합을 구한다.
   ```cpp
   flag[cnt] = false;
   makeSubset(cnt + 1);
   flag[cnt] = true;
   makeSubset(cnt + 1);
   ```
   1. `idx[제거할 괄호에 해당하는 인덱스]`에 true 값을 설정한다.
   2. 주어진 문자열에서 `i`번째 문자의 `idx[i]` 값이 false인 것만 `temp`에 덧붙인다.
   3. `temp`를 정답 벡터에 추가한다.
3. 정답 벡터를 정렬하고 중복을 제거한 뒤 출력한다.
