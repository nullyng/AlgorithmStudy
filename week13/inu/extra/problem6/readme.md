# 문제 개요

문제 : [NULL 처리하기](https://school.programmers.co.kr/learn/courses/30/lessons/59410)

문제 분류 : sql

# 문제 풀이

```sql
SELECT ANIMAL_TYPE, IFNULL(NAME, 'No name') AS NAME, SEX_UPON_INTAKE
FROM ANIMAL_INS
ORDER BY ANIMAL_ID;
```
