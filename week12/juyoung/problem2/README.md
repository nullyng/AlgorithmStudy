# 문제 개요

문제 : [큰 수 만들기](https://school.programmers.co.kr/learn/courses/30/lessons/42883)

문제 분류 : 그리디

# 문제 풀이

숫자를 한 자리씩 탐색하며 앞뒤 대소를 비교한다.  
앞 숫자보다 뒷 숫자가 크다면, 앞 숫자에 해당하는 숫자를 제거한다.

이때 전체적인 숫자의 길이가 줄어들기 때문에 탐색하는 인덱스도 감소시켜줘야 하는데  
나의 경우 for문을 사용하였기 때문에 이후 1이 더해지는 것을 생각해서 아래와 같이 감소시켰다.

- 현재 인덱스가 0인 경우, 1만큼 감소시키고
- 현재 인덱스가 0보다 큰 경우, 2만큼 감소시킨다.

문제의 예시인 `4177252841`로 예를 들자면, 먼저 `4`와 `1`을 비교한다.  
이때 앞 숫자인 `4`가 뒷 숫자인 `1`보다 크므로 그냥 넘어간다.

다음으로 `1`이 `7`보다 작으므로 `1`을 제거하여 `477242841`이 된다.  
현재 탐색하던 인덱스는 1이었으며 0보다 크기 때문에 2만큼 감소시켜 현재의 인덱스가 -1이 된다.  
이후 for문의 증가문으로 인해 1이 증가하여 다시 0번째 숫자부터 탐색을 시작한다.

이렇게 하면 최종적으로 `775841`이 남는다.

그리고 주의해야 할 점은, **탐색이 끝난 후 제거해야 할 개수가 남아있을 수 있다**는 것이다.  
탐색에 의해 큰 수→작은 수의 순서로 숫자가 구성되기 때문에,  
탐색이 종료된 후에 제거해야 할 게 남았다면 숫자의 끝부분에서 남은 개수만큼 제거하면 된다.
