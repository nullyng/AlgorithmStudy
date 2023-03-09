clarify

로봇에 내리는 명령에서
처음 숫자는 명령 내리는 로봇
이는 로봇도 index로 번호가 매겨져있다는 건가?

```
원문에는 "Then follow N lines with two integers, 1 ≤ Xi ≤ A, 1 ≤ Yi ≤ B and one letter (N, S, E or W), giving the starting position and direction of each robot, in order from 1 through N." 라는 말이 있습니다. 즉, 생각하신대로인 듯합니다.
```

solution

vector로 index별 로봇 현 위치, 방향 저장해놓고
map에는 0, 1로 해당 위치에 로봇이 존재하는지만

포문 돌면서
불러온 로봇이 직진해야하면 map에 없애고 앞의 위치에 표시.

TC
O(M \* 100)
사실상 O(M)이고 0ms.
