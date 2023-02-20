# 문제 개요

문제 : [과일로 만든 아이스크림 고르기](https://school.programmers.co.kr/learn/courses/30/lessons/133025)

문제 분류 : sql

# 문제 풀이
```sql
SELECT A.FLAVOR
FROM FIRST_HALF A
JOIN ICECREAM_INFO B ON A.FLAVOR = B.FLAVOR
WHERE TOTAL_ORDER > 3000 AND INGREDIENT_TYPE LIKE "f%";
```