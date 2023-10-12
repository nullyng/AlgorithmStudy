# 문제 개요

문제: [오목](https://www.acmicpc.net/problem/2615)

문제 분류: 구현, 브루트포스

# 문제 풀이

바둑이 있는 칸에서 4방향의 직선 상에 있는 연속된 같은 색의 바둑알 개수를 세아린다. 즉 8방향에 대해 모두 검사하는데, 이는 같은 색의 바둑알이 6개 이상 있는 경우를 검사하기 위해서이다.

따라서 방향을 가리키는 배열을 2차원으로 선언하였다.

```cpp
int dy[2][4] = {{0, 1, 1, 1}, {0, -1, -1, -1}};
int dx[2][4] = {{1, 1, 0, -1}, {-1, -1, 0, 1}};
```

`[0][0]`: 오른쪽  
`[0][1]`: 오른쪽 아래 대각선  
`[0][2]`: 아래  
`[0][3]`: 왼쪽 아래 대각선

각 원소가 가리키는 방향은 위와 같으며 `[1][0~4]`의 경우 각각 반대 방향을 가리킨다.

바둑알이 놓인 칸을 발견하면 4개의 방향(오른쪽, 오른쪽 아래 대각선, 아래, 왼쪽 아래 대각선) 중 한 방향에 대해 같은 색의 연속된 바둑알이 몇 개인지 탐색한다. 또한 그 방향의 반대 방향에 대해서도 탐색한다.

이렇게 탐색해서 해당 직선 상에 같은색의 연속된 바둑알이 몇 개인지 세아리고, 그 개수가 5인 경우에만 정답을 업데이트 한다. 이때 가장 왼쪽에 있는 바둑알을 찾아야 하기 때문에 현재 정답인 바둑알의 열보다 더 왼쪽 열에 있는 바둑알인 경우에만 정답으로 업데이트 한다.