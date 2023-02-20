# 문제 개요

문제 : [자동차 평균 대여 기간 구하기](https://school.programmers.co.kr/learn/courses/30/lessons/157342)

문제 분류 : SQL

# 문제 풀이

대여 기간을 그냥 `END_DATE-START_DATE`로 계산했더니 틀려서 기간 계산에 쓰이는 함수를 찾아봤다.

## DATEDIFF 함수

두 기간 사이의 일수를 구하는 함수이다.

```SQL
DATEDIFF(종료 시간, 시작 시간);
```

아래와 같은 경우에는 4를 반환하는데, 문제의 조건에 따라 DATEDIFF 함수의 반환값에서 1을 더한 값이 대여 기간이 된다.

```SQL
SELECT DATEDIFF('2023-02-24','2023-02-20');
```
