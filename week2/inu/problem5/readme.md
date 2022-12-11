# 문제 개요

문제 : [연구소](https://www.acmicpc.net/problem/14502)

문제 분류 : bfs

# 문제 풀이

벽을 세울 수 있는 모든 경우의 수를 구한다. 이는 조합으로 해결할 수 있다.

```c++
void comb(int x, int y, int cnt) {
	if (cnt == 3) {
		int area = virus();
		max_area = area > max_area ? area : max_area;
		return;
	}

	int _x = x;
	int _y = y;

	while (1) {
		if (map[_x][_y] == 0) {
			map[_x][_y] = 1;
			comb(_x, _y, cnt + 1);
			map[_x][_y] = 0;
		}

		_y++;

		if (_y >= M) {
			_y = 0;
			if (++_x >= N)
				break;
		}
	}
}
```

`map[_x][_y]`가 0일 때까지 해당 좌표를 찾고 0인 곳은 벽을 세워서 다음 좌표로 넘어간다.  
그렇게 cnt가 3이 되면 BFS로 바이러스를 퍼뜨려서 안전지대 갯수를 구하면 된다.
