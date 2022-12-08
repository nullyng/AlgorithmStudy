# 문제 개요

문제 : [ABCDE](https://www.acmicpc.net/problem/13023)

문제 분류 : DFS

# 문제 풀이

A-B-C-D-E처럼 depth가 5만큼 들어가는 관계가 하나라도 있다면 1을 출력하는 문제였다.

1. 벡터 배열로 인접리스트 구성
2. 인접리스트를 바탕으로 모든 번호에 대해 깊이 우선 탐색
   - depth가 5인 관계가 있다면 `flag`를 true로 업데이트
   - `flag`가 true인 경우 탐색 종료
3. `flag` 출력

### :mag_right: 틀린 이유

7%에서 계속 틀리길래 질문 게시판의 반례를 찾아봤다.

```plain
5 4
0 1
1 2
2 3
3 0
```

위 입력의 정답은 0이다. 그런데 내 코드에서는 1이 나왔다.  
0-1-2-3에서 멈추지 않고 0-1-2-3-0까지 가면서 depth가 5가 되어 그런 거였는데,  
처음 `dfs`를 호출할 때 해당하는 번호의 방문 여부를 true로 바꿔주지 않은 것이 문제였다.