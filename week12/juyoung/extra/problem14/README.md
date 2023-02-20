# 문제 개요

문제 : [3월에 태어난 여성 회원 목록 출력하기](https://school.programmers.co.kr/learn/courses/30/lessons/131120)

문제 분류 : SQL

# 문제 풀이

## DATE_FORMAT 함수

두 기간 사이의 일수를 구하는 함수이다.

```SQL
# 연도(4자리)-월-일
DATE_FORMAT(기준 날짜, '%Y-%m-%d');

# 연도(2자리)/월/일
DATE_FORMAT(기준 날짜, '%y/%m/%d');

# 연도만 뽑아내고 싶은 경우
DATE_FORMAT(기준 날짜, '%Y');
```
