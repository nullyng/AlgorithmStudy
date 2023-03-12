clarify

수업 끝난 시간과 시작 시간이 같으면 한 강의실 가능하다.

떠오르는 풀이법

map + prefix sum을 사용
map에 start++, end-- 해서
prefix sum 구하기.
거기서 max값이 정답.

map에 값 넣기 O(NlogN)
prefix sum 구하기 O(N)

total TC : O(NlogN)

---

인터넷에서 찾은 priority queue 사용법

시작 시간 기준 오름차순 정렬하고
pq에 끝 시간 작은 게 우선순위 크도록 넣어줌
만약 젤 위 시간이 현 시작 시간보다 작거나 같다 => pop 하고 현 시각 투입
아니다 => 현 시각 투입

total TC : O(NlogN)

---

결론
시간을 다룬다는 점에서 pq 사용을 인지하기가 어려움
prefix sum에 대한 개념만 이해한다면
내 풀이법이 더 직관적이고 코드도 깔끔할듯?
