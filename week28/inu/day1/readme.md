# 문제 개요

문제 : [용액](https://www.acmicpc.net/problem/2467)

문제 분류 : 투포인터

# 문제 풀이

0에 가까우려면 절대값이 비슷한 음수, 양수를 더해야 한다.  
따라서 정렬된 배열의 맨 앞(s)과 맨 뒤(e)를 시작으로 차례대로 더하면서 답을 구한다.  
이 때, s + e가 음수면 s++을 하고 양수면 e--를 하면 된다.
