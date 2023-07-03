# 문제 개요

문제 : [알파벳](https://www.acmicpc.net/problem/1987)

문제 분류 : DFS

DFS를 수행하며 이미 지나온 알파벳 칸을 체크하고 depth를 세아린다. 더이상 탐색할 수 없다면, 해당 칸의 알파벳에 대해 아직 지나간 적 없었던 것으로 되돌린다.

```cpp
alphabet[board[ny][nx]-'A'] = true;
dfs(ny, nx, depth + 1);
alphabet[board[ny][nx]-'A'] = false;
```
