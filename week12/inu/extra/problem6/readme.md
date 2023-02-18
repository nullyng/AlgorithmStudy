# 문제 개요

문제 : [서울에 위치한 식당목록 출력하기](https://school.programmers.co.kr/learn/courses/30/lessons/131118)

문제 분류 : SQL

# 문제 풀이

```sql
SELECT A.REST_ID, REST_NAME, FOOD_TYPE, FAVORITES, ADDRESS, ROUND(AVG(REVIEW_SCORE), 2) as SCORE
FROM REST_INFO A
JOIN REST_REVIEW B on A.REST_ID = B.REST_ID
GROUP BY A.REST_ID
HAVING ADDRESS LIKE "서울%"
ORDER BY SCORE desc, FAVORITES desc;
```
