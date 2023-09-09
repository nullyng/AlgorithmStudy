# 문제 개요

문제: [집합의 표현](https://www.acmicpc.net/problem/1717)

문제 분류: Union-Find

# 문제 풀이

Union-Find 알고리즘을 통해 간단히 풀 수 있었다.

- 합집합 연산일 경우 두 집합을 Union한다.
- 같은 집합에 포함되어 있는지 확인하는 연산일 경우 Find로 각 집합의 루트를 찾아서 그 값이 같다면 "YES", 다르다면 "NO"를 출력한다.
