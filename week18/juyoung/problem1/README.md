# 문제 개요

문제 : [여러분의 다리가 되어 드리겠습니다!](https://www.acmicpc.net/problem/17352)

문제 분류 : 분리집합

# 문제 풀이

1. 입력되는 섬들을 Union으로 연결한다.
2. 1번 섬과 연결된 섬이 아닌 섬을 출력한다.  
    즉, 1번 섬의 루트와 루트가 다른 섬을 출력한다.
   ```cpp
   int r = Find(1);
   for (int i = 2; i <= N; i++) {
    if (r != Find(root[i])) {
      cout << r << " " << i << "\n";
      break;
    }
   }
   ```
