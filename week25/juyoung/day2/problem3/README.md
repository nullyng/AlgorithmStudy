# 문제 개요

문제: [암호 만들기](https://www.acmicpc.net/problem/1759)

문제 분류: 조합론, 백트래킹

# 문제 풀이

1. 입력 받은 문자를 정렬한다.
2. 주어진 문자 중 `L`개를 중복 없이, 순서를 고려해서 고른다.
3. 백트래킹을 통해 `L`개를 모두 골랐을 때 자음과 모음의 개수를 센다.
4. 자음과 모음 개수가 문제 조건을 만족하면 출력한다.
