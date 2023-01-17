# 문제 개요

문제 : [거짓말](https://www.acmicpc.net/problem/1043)

문제 분류 : 분리집합

# 문제 풀이

findParent를 할때 깊이가 1인 tree로 만들어주어 나중에 truth를 판단할 때, 자식이 진실을 아는 사람이면 해당 부모가 진실을 아는 사람이라고 판단하여

만약 자식이 진실이 아닌지 모를지라도 부모를 보면 해당 집합이 진실을 아는지의 유무를 파악할 수 있다.

일단 모든 파티를 돌며 집합을 결정하고 진실을 아는 사람들이 속해있는 집합의 부모는 진실을 알고있기 때문에 다시 한번 파티를 돌며 파티의 구성원의 부모를 알아내고

부모 중 진실을 알고 있다면 해당 파티는 제외한다.