# 문제 개요

문제 : [스카이라인 쉬운거](https://www.acmicpc.net/problem/1863)

문제 분류 : 스택

# 문제 풀이

고도를 통해 건물의 개수를 알아낼 수 있으므로 좌표 x, y 중에서 실제로 쓰이는 값은 y뿐이다.  
y값을 스택에 넣으면서 스택의 top과 현재 y값을 비교하여 문제를 풀 수 있다.

1. 스택의 top이 현재 y보다 작아질 때까지 pop한다.
   - 이때 top이 y가 아닌 경우에만 정답을 카운트한다.
2. 스택에 y를 push한다.

위 과정을 n번 반복한 후, 마지막에는 y값을 0으로 두고 위 과정을 한 번 더 수행한다.

```
6
1 1
2 2
5 3
6 1
7 3
8 2
```

위와 같은 예제는 아래와 같이 풀이할 수 있다.

![IMG_83CEB6EEEB06-1](https://github.com/nullyng/AlgorithmStudy/assets/57346428/823eaf1b-023a-4d78-9f00-ab5516c90cf5)

계속해서 push하다가 (6,1)일 때 스택의 top인 3보다 현재 y값인 1이 더 작으므로 스택의 top이 1보다 작아질 때까지 pop한다.  
이때 스택에 있던 1에 대해서는 정답을 카운트하지 않는다.

핑크색으로 표시된 부분이 방금 카운트된 정답에 대한 건물이다.

![IMG_0062D609C899-1](https://github.com/nullyng/AlgorithmStudy/assets/57346428/356cdfe2-ca22-492a-93d4-5a76ca8a2a73)

마찬가지로 push하다가 (8,2)일 때 스택에서 조건에 맞는 값을 pop하고 정답을 카운트한다.

![IMG_10F0F53117F2-1](https://github.com/nullyng/AlgorithmStudy/assets/57346428/6c4925b6-f4e1-4d80-b6dd-b3439d1a10a5)

이렇게 n번의 수행이 끝났다면, 마지막으로 y값을 0으로 두고 한 번 더 수행한다.  
이때 스택에 있던 남은 값들이 전부 pop되면서 정답이 5가 된다.
