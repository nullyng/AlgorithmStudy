# 문제 개요

문제 : [3020 개똥벌레](https://www.acmicpc.net/problem/3020)

문제 분류 : 이분 탐색

# 문제 풀이
1. 종유석과 석순을 각각 다른 배열에 저장한 다음 크기순으로 정렬한다.

2. 누적합으로 각 높이별로 파괴해야 하는 종유석과 석순의 갯수를 구한다.

3. 종유석과 석순 갯수를 구한 것을 다시 크기순으로 정렬한다.

4. upper_bound로 최소 갯수보다 커지는 인덱스를 찾아 해당 인덱스 - 1을 하면 구간 갯수가 된다.