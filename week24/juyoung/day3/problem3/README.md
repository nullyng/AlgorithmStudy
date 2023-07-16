# 문제 개요

문제 : [겹치는 건 싫어](https://www.acmicpc.net/problem/20922)

문제 분류 : 투포인터

# 문제 풀이

dp로 풀다가 안돼서 [다른 사람 풀이](https://ongveloper.tistory.com/299)를 참고했다.

- `start`: 최장 연속 부분 수열의 시작 지점
- `i`: 현재 수열의 요소
- `cnt`: 수의 등장 횟수

cnt에 수의 등장 횟수를 저장하다가 `K`보다 커진 경우,  
그 수의 등장 횟수가 `K`보다 작아질 때까지 등장 횟수를 1만큼 감소시키고 `start`를 1만큼 증가시킨다.

이렇게 진행하면서 `answer`와 투포인터 간의 거리 `start-i+1`을 비교하여 더 큰 값을 `ansewr`에 저장한다.

```
10 3
1 1 1 2 2 1 1 1 1 1
```

위와 같은 예시가 있을 때 아래와 같이 풀이할 수 있다.

<img src="https://github.com/nullyng/AlgorithmStudy/assets/57346428/1eda9586-1dd0-42e7-a9dd-d54227d18d97" width="600px">

우선 `i`가 5인 시점에서 `cnt[1]`이 4가 되어 `K`보다 커진다.  
이때 `cnt[1]`을 다시 1만큼 줄여주고, `start`를 오른쪽으로 한 칸 옮긴다.

<img src="https://github.com/nullyng/AlgorithmStudy/assets/57346428/1a255241-e043-4783-a496-fd742ea0c6a0" width="600px">

그럼 위와 같이 된다.

<img src="https://github.com/nullyng/AlgorithmStudy/assets/57346428/385cc0b0-e9ff-401b-95a9-7ea4b137b20a" width="600px">

이후 계속해서 진행하다가 `i`가 8이 된 시점에 `cnt[1]`이 `K`보다 커진다.  
이때 `cnt[1]`이 `K`보다 작아질 때까지 `cnt[1]`을 감소시키고 `start`를 오른쪽으로 한 칸씩 옮긴다.

<img src="https://github.com/nullyng/AlgorithmStudy/assets/57346428/5f19078a-2d1c-44e6-ac60-6bcfa03ced19" width="600px">

그러고 나면 위와 같은 모양이 되고, 마지막으로 끝까지 진행하면 아래와 같이 된다.

<img src="https://github.com/nullyng/AlgorithmStudy/assets/57346428/acc5959d-027d-492f-b798-5d16f86ca6b5" width="600px">

마지막에 투포인터 간의 거리가 3이 되는데, 이 값이 최댓값이므로 출력한다.
