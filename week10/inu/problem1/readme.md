# 문제 개요

문제 : [개인정보 수집 유효기간](https://school.programmers.co.kr/learn/courses/30/lessons/150370)

문제 분류 : 구현

# 문제 풀이

개인정보 수집 기간을 year, month, day로 나눠서 생각해보자.

일단, month에 약관에 해당하는 달을 더한다.  
month가 12보다 커진다면 year과 month는 다음과 같다.

- year += month / 12
- month %= 12

이 때, month가 0이 된다면 개인정보 수집 기간이 12월인데 약관 기간이 24달인 경우가 될 수 있다.  
따라서 month는 12가 되고 year은 1을 빼주어야 한다.

day는 1만 빼주면 되는데 1을 뺀 값이 0이 될 수 있다.  
이 때 day는 28이고 month에서도 1을 빼주어야 한다.  
이 때도 month가 0이 된다면 month는 12가 되고 year에서 1을 빼주어야 한다.
