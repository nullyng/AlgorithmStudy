# 문제 개요

문제 : [운동](https://www.acmicpc.net/problem/1956)

문제 분류 : 플로이드와샬

# 문제 풀이

문제에서 주어지는 마을의 개수가 최대 400개로 삼중 반복문을 돌려도 충분했기 때문에 플로이드 와샬 알고리즘을 사용했다.

모든 마을 사이의 최단 거리를 구하면서 **출발지와 도착지가 자기 자신인 경우에만 `answer`과 비교하여 더 적은 값을 저장한다.**

```cpp
for (int k = 1; k <= V; k++) {
  for (int i = 1; i <= V; i++) {
    for (int j = 1; j <= V; j++) {
      if(dist[i][j] > dist[i][k] + dist[k][j]) {
        dist[i][j] = dist[i][k] + dist[k][j];
        if(i==j) answer = min(answer, dist[i][j]);
      }
    }
  }
}
```

이후 `answer`가 초기값과 같으면 그대로 출력하고 그렇지 않으면 `-1`을 출력한다.
