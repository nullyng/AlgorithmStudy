# 문제 개요

문제 : [자동차 대여 기록 별 대여 금액 구하기](https://school.programmers.co.kr/learn/courses/30/lessons/151141)

문제 분류 : SQL

# 문제 풀이

- WITH 문으로 가상 테이블 만들기

  ```SQL
  WITH TBL AS
  (
    SELECT 쿼리
  )

  SELECT NAME, AGE FROM TBL;
  ```

- CASE 문
  ```SQL
  CASE
    WHEN 조건 THEN '반환 값'
    WHEN 조건 THEN '반환 값'
    ELSE 'WHEN 조건에 해당 안되는 경우 반환 값'
  END
  ```
