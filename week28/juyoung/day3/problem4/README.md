# 문제 개요

문제: [순회강연](https://www.acmicpc.net/problem/2109)

문제 분류: 그리디

# 문제 풀이

[다른 사람 풀이](https://leesh111112.tistory.com/80)를 참고했다.

입력 시 벡터를 선언하고 `벡터[날짜]`에 해당하는 강연료를 추가한다.

이후 벡터의 뒤에서부터(10000일부터 1일까지) 벡터[날짜]에 해당하는 강연이 있다면 이를 전부 우선순위큐에 push한다. 그리고 매일 우선순위큐의 top에 있는 강연료를 정답에 더한다.

```
7
3 1
4 1
10 2
15 2
2 10
5 10
6 10
```

위의 입력이 주어졌을 때 아래 그림과 같이 풀이할 수 있다.

<img src="https://github.com/nullyng/AlgorithmStudy/assets/57346428/431c57b8-40b1-4b96-8b11-db3a09eef45f" width="600px">