# 문제 개요

문제 : [조이스틱](https://school.programmers.co.kr/learn/courses/30/lessons/42860)

문제 분류 : 그리디

# 문제 풀이

[다른 사람 풀이](https://googleyness.tistory.com/16)를 참고했다.

주어진 이름의 알파벳을 차례대로 탐색하며 각 알파벳으로 변경하기 위한 조작 횟수를 누적하여 더하고, 최소 이동 거리를 업데이트 하는 방식으로 풀이할 수 있었다.

`curr`=현재 문자, `next`='A'가 아닌 다음 문자, `len`=주어진 이름의 길이  
위와 같다고 할 때 최소 이동 거리는 아래와 같다.

1. 첫 문자부터 마지막 문자까지 차례로 이동 → **`len`-1**
2. 방향을 바꾸며 탐색(`curr`=현재 문자, `next`='A'가 아닌 다음 문자, `len`)
   1. `curr`까지는 정방향으로 이동했다가 `next`까지 역방향으로 이동  
      → **2\*`curr`+(`len`-`next`)**
   2. 역방향으로 `next`까지 이동했다가 `curr`까지 정방향으로 이동  
      -> **2\*(`len`-`next`)+`curr`**

위를 적용해서 아래와 같은 순서로 풀이한다.

1. 처음 최소 이동 거리 `move`는 주어진 이름의 길이-1로 초기화 한다.
   - 이는 제일 첫 문자부터 마지막 문자까지 차례대로 이동하는 횟수이다.
2. 주어진 이름의 알파벳을 차례대로 탐색한다.
   1. 'A'에서 현재 알파벳으로 바꾸기 위한 조작 횟수를 정답에 더한다.
   2. 현재 문자 다음의 'A'가 아닌 문자를 찾고, 최소 이동 거리를 구한다.
      - min(현재 문자까지 정방향 이동 후 다음 문자까지 역방향 이동,  
        다음 문자까지 역방향 이동 후 현재 문자까지 정방향 이동)
   3. 기존의 최소 이동 거리와 비교하여 더 작은 값으로 업데이트한다.
      - min(기존의 최소 이동 거리, 새로 구한 최소 이동 거리)
3. 정답에 최종적으로 구한 최소 이동 거리를 더한다.