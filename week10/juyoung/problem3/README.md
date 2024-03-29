# 문제 개요

문제 : [이모티콘 할인행사](https://school.programmers.co.kr/learn/courses/30/lessons/150368)

문제 분류 : 2023 KAKAO BLIND RECRUITMENT

# 문제 풀이

모든 경우를 다 계산했다.

1. 사용자는 최대 `100명`이고
2. 이모티콘의 개수는 최대 `7개`이며
3. 이모티콘 할인율은 10%, 20%, 30%, 40%의 `4개` 중 하나이다.

따라서 중복 순열을 만든다고 했을 때, 4^7 = 16,384개의 경우의 수가 나올 수 있으며  
각 경우의 수에 대해 각 사용자의 이모티콘 구매 금액을 계산한다면 16,000 \* 100 \* 7 = 11,400,000

즉, 1100만 번의 연산을 수행하기 때문에 모든 경우를 계산해도 시간 초과가 나지 않을 거라고 판단했다.

문제는 아래와 같은 순서로 풀이했다.

1. 각 이모티콘의 할인율에 대해 중복 순열을 만든다.
2. 만든 순열을 바탕으로 할인율을 적용하고, 각 사용자가 구매할 이모티콘의 총 금액을 계산한다.
   - 이모티콘 플러스에 가입한다면 `plus`를 1 증가시킨다.
   - 이모티콘 플러스에 가입하지 않는다면 `sum`에 판매액을 더한다.
3. `plus`와 `sum`의 값에 따라 정답을 업데이트한다.
   - 이모티콘 플러스 가입자의 수를 늘리는 것이 우선이므로 `plus`를 먼저 비교한다.
   - 현재 정답의 플러스 가입자보다 `plus`가 크다면 정답을 `plus`와 `sum`으로 업데이트한다.
   - 현재 정답의 플러스 가입자와 `plus`가 같다면 현재 정답의 판매액을 `sum`과 비교한다.

할인율을 적용할 때 처음에는 아래와 같이 계산했는데, 테스트 13, 15, 18을 통과하지 못했다.  
(`p_emo`는 각 이모티콘의 `{퍼센트, 퍼센트를 적용한 가격}`을 저장하는 배열이다.)

```cpp
p_emo[i] = {perm[i], emoticons[i] * (1 - perm[i]*0.01)};
```

따라서 아래와 같이 계산을 바꿨더니 전부 통과되었다.

```cpp
p_emo[i] = {perm[i], emoticons[i] * (100-perm[i]) / 100};
```
