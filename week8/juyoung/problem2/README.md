# 문제 개요

문제 : [호석이 두 마리 치킨](https://www.acmicpc.net/problem/21278)

문제 분류 : 플로이드와샬

# 문제 풀이

주어지는 건물의 최대 개수가 100개로 작고, 모든 건물에서의 접근성의 합을 최소화하려고 하기 때문에 플로이드 와샬 알고리즘을 적용할 수 있다.

1. 플로이드 와샬 알고리즘을 적용하여 각 건물에 대한 최단 거리 테이블을 만든다.
2. 건물 중 2개를 뽑는 조합을 구한다.
3. 뽑은 두 건물에 대한 모든 건물의 최단 거리 합\*2가 `answer`보다 크다면 정답을 업데이트 한다.
4. 정답을 출력한다.