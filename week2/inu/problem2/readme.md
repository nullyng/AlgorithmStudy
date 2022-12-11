# 문제 개요

문제 : [단어 변환](https://school.programmers.co.kr/learn/courses/30/lessons/43163)

문제 분류 : dfs

# 문제 풀이

먼저, target이 words에 있는지 검사한다.

target이 있으면 words에 있는 단어(word)와 현재 단어(current)의 문자를 하나씩 비교한다.

두 단어 사이에 서로 다른 문자가 1개만 있다면 word를 current로 해서 다시 다른 단어와 문자를 비교하는 작업을 수행한다.

이전에 비교 작업을 했던 단어는 visited를 체크해줘야 한다.

그리고 경로 탐색이 완료되었다면 해당 단어의 visited를 다시 false로 해줘야 한다.

최소 변환 단계를 찾아야 하기 때문에 현재 변환 횟수가 최소 변환 횟수보다 크거나 같으면 함수를 종료해주면 된다.
