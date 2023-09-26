# 문제 개요

문제: [멍멍이 쓰다듬기](https://www.acmicpc.net/problem/1669)

문제 분류: 수학

# 문제 풀이

[다른 사람 풀이](https://jovialcode.tistory.com/9)와 [다른 사람 코드](https://j3sung.tistory.com/64)를 참고했다.

만약 원숭이와 개의 키 차이별 정답을 표로 표현하면 아래와 같다.

![IMG_D8B7CAD8C484-1](https://github.com/nullyng/AlgorithmStudy/assets/57346428/b07fb91b-9188-4af9-8d46-6ee2bb798b28)

자라야 하는 키가 N^2일 때와 N^2-N일 때가 자라는 데 같은 기간이 걸리는 키 중 마지막임을 알 수 있다.  
예를 들어 원숭이와 개가 키가 같아지는 데 3일이 걸리는 키 차이는 3cm, 4cm이고 이 중 마지막인 4cm는 N^2이다. 또한 키가 같아지는 데 4일이 걸리는 건 5cm, 6cm이며 이 중 마지막인 6cm는 N^2-2이다.

따라서 이를 이용하여 코드를 작성할 수 있다.
