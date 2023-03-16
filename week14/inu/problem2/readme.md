# 문제 개요

문제 : [사분면](https://www.acmicpc.net/problem/1891)

문제 분류 : 분할정복

# 문제 풀이

먼저 현재 사분면의 중심좌표를 구한다.  
처음 센터를 (0, 0)으로 설정하고 사분면의 번호에 따라 중심좌표를 옮겨가면서 구할 수 있다.  
그리고 중심좌표를 이동시키는데 한 칸당 좌표가 2씩 이동하는걸 고려해서 옮긴다.

이동한 중심좌표가 전체 사분면 영역을 벗어나면 -1을 출력한다.  
그렇지 않으면 (0, 0)을 기준으로 좌표의 사분면 번호를 구하고 다시 센터를 옮겨가면서 나머지 사분면 번호를 구하면 된다.