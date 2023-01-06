# 문제 개요

문제 : [네트워크](https://school.programmers.co.kr/learn/courses/30/lessons/43162)

문제 분류 : 분리집합

# 문제 풀이

Union으로 연결한 후, Find를 통해 묶인 그룹(네트워크)이 몇 개인지 확인한다.

`visited`에 방문한 루트에 대해 방문 여부를 표기하여 `visited`가 false인 경우에만 `answer`를 1만큼 증가시킨다.
