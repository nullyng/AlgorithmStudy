# 문제 개요

문제 : [조건에 맞는 도서와 저자 리스트 출력하기](https://school.programmers.co.kr/learn/courses/30/lessons/144854)

문제 분류 : sql

# 문제 풀이

```sql
SELECT BOOK_ID, AUTHOR_NAME, DATE_FORMAT(PUBLISHED_DATE, '%Y-%m-%d')
FROM BOOK A
JOIN AUTHOR B ON A.AUTHOR_ID = B.AUTHOR_ID
WHERE CATEGORY = '경제'
ORDER BY PUBLISHED_DATE;
```
