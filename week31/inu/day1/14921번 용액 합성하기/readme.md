# 문제 개요

문제 : [용액 합성하기](https://www.acmicpc.net/problem/14921)

문제 분류 : 투포인터

# 문제 풀이

배열의 맨 앞 (i), 맨 뒤(j)를 각각 가리키는 변수를 두고 합을 구한다.  
합의 절댓값과 현재 답의 절댓값을 비교해서 절댓값이 더 작은 것으로 업데이트한다.  
합이 음수면 i++을 하고 합이 양수면 j--를 하면서 위 과정을 반복한다.
