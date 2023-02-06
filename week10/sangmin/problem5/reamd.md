# 문제 개요

문제 : [표 병합](https://school.programmers.co.kr/learn/courses/30/lessons/150366)

문제 분류 : 구현, 유니온 파인드

# 문제 풀이

셀을 주어진 커맨드에 따라 동작하는 문제이다.

커맨드는 크게 UPDATE, MERGE, UNMERGE, PRINT가 있다.

모든 커맨드의 동작을 편하게 관리하기위해 각자의 cell은 부모가 존재한다.

cell의 초기 부모는 자기 자신이며 UPDATE를 할 경우 해당 cell의 부모를 찾아 업데이트를 해준다.

MERGE를 할 경우 셀 자체를 병합시키는게 아닌 각자의 부모를 찾아 MERGE의 조건에 맞추어 합쳐준다.

UNMERGE 또한 마찬가지로 해당 부모를 부모로 두고 있는 cell을 전부 찾아 초기화 시켜준 뒤, r,c에만 value를 넣어준다.