# 문제 개요

문제 : [개인정보 수집 유효기간](https://school.programmers.co.kr/learn/courses/30/lessons/150370)

문제 분류 : 2023 KAKAO BLIND RECRUITMENT

# 문제 풀이

1. `today`에서 오늘의 년, 월, 일을 파싱한다.
2. `terms`의 약관을 key, 유효기간을 value로 하여 map에 저장한다.
3. `privacies`를 순회하며 각 개인정보 수집 일자의 유효기간의 마지막 날을 계산한다.
   1. 개인정보 수집 일자에서 년, 월, 일, 약관 종류를 파싱한다.
   2. 일을 1만큼 감소시킨다.
      - 이때, 일이 0이 되면 일에는 28을 저장하고 월을 1만큼 감소시킨다.
      - 이때, 월이 0이 되면 월에는 12를 저장하고 년을 1만큼 감소시킨다.
   3. 약관 종류를 map에서 조회하여 월과 년을 계산한다.
      - 유효기간을 12로 나눈 나머지를 월에 더한다.
      - 유효기간을 년 단위로 치환한 값을 년에 더한다.
      - 이때, 월이 12를 넘으면 년을 1만큼 증가시키고 월을 12만큼 감소시킨다.
4. 3번 단계에서 계산한 날짜가 오늘보다 이전 날짜라면 `answer`에 번호를 저장한다.