# 문제 개요

문제 : [없어진 기록 찾기](https://school.programmers.co.kr/learn/courses/30/lessons/59042)

문제 분류 : SQL

# 문제 풀이

## OUTER JOIN

![IMG_1895DBBAE619-1](https://user-images.githubusercontent.com/57346428/220297295-85444657-e438-4a2e-a48d-2cdc09b65840.jpeg)

### 📌 Left Outer Join

첫 번째 테이블의 데이터를 모두 선택 후, 두 번째 테이블의 데이터를 결합 조건에 따라 매칭

```SQL
FROM ANIMAL_INS AI
    LEFT OUTER JOIN ANIMAL_OUTS AO
    ON AI.ANIMAL_ID = AO.ANIMAL_ID
```

### 📌 Right Outer Join

두 번째 테이블의 데이터를 모두 선택 후, 첫 번째 테이블의 데이터를 결합 조건에 따라 매칭

```SQL
FROM ANIMAL_INS AI
   RIGHT OUTER JOIN ANIMAL_OUTS AO
   ON AI.ANIMAL_ID = AO.ANIMAL_ID
```

매칭되는 데이터가 없는 경우 그 값을 NULL로 표현한다.  
또한 `A left join B`와 `B right join A`는 같다.
