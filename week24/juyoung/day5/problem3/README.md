# 문제 개요

문제 : [별 찍기 - 11](https://www.acmicpc.net/problem/2448)

문제 분류 : 재귀

# 문제 풀이

[다른 사람 풀이](https://icechou.tistory.com/106)를 참고했다.

재귀를 통해 `N`이 3이 되었을 때 해당하는 위치에 작은 삼각형을 출력한다.

만약 `N`이 6이면 아래와 같은 별이 찍히는데, 하나의 큰 삼각형 내부에 세 개의 작은 삼각형이 있다.

<img src="https://github.com/nullyng/AlgorithmStudy/assets/57346428/134cfa7d-b4f1-4257-8b13-62fe33356ef7" width="600px">

<img src="https://github.com/nullyng/AlgorithmStudy/assets/57346428/3a8222b6-4ccf-410b-a00f-9ba54b477165" width="600px">

이 삼각형을 출력하기 위해 재귀적으로 `N/2`와 각 삼각형의 위 꼭짓점의 위치를 넘겨준다.

그리고 배열에 각 위치에 출력할 값을 저장해서 출력한다.

<img src="https://github.com/nullyng/AlgorithmStudy/assets/57346428/1608c946-060d-44ac-96db-888ef27eb692" width="600px">

```cpp
void print(int N, int x, int y) {
  if(N==3) {
      star[y][x] = '*';

      star[y+1][x-1] = '*';
      star[y+1][x+1] = '*';

      star[y+2][x-2] = '*';
      star[y+2][x-1] = '*';
      star[y+2][x] = '*';
      star[y+2][x+1] = '*';
      star[y+2][x+2] = '*';
  } else {
      print(N/2, x, y);
      print(N/2, x-N/2, y+N/2);
      print(N/2, x-N/2+N, y+N/2);
  }
}
```
