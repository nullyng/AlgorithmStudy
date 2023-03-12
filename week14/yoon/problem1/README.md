clarify

Given the postorder and inorder, find the preorder traversal.

preorder
본인 출력, left 출력, right 출력

inorder
left 출력, 본인 출력, right 출력 순

postorder
left 출력, right 출력, 본인 출력 순

two pointer with inorder, postorder head.

if different value in each, then go ahead postorder's head.
in progress, there should be same value.
finishing this progress, there became same value that saved in postorder.

이렇게 해서 순서를 얻을 수 있다
right child에 대해서는 또 여러 개의 합을 만나는데, 여기서도 해당 함수를 돌리면 된다.

이제 여기서 포인트
어떻게하면 preorder를 바로 돌릴 것인가?

inorder
4 2 657
=> pre
2 4 abc -> 2 4 bac
=>
24567 1 3
1 24567 3

이렇게 하면

TC O(N)
SC O(N)
가능하겠는데?

deque, two pointer, recursion

값 확인.
같다 => count 확인
count가 0이다
적절한 위치에 넣어준다. push_back

        count가 0이 아니다
        센터라는 뜻
        push_front 처리
        count한 것들 함수에 다시 넣어줘.

다르다 => inorder 정지
postorder 계속 전진하면서 다른 부분 size 확인
해당 부분은 divide에 다시 넣어줌

---

긴급 시간초과

시간초과 나는 이유가 멀까
번호가 중복 없다고 했는데
알고리즘상으로 오류는 없고

우측으로 진행하는 트리라 생각해보면
N, N-2, N-4, N-6 ...
최악의 경우 이렇게 진행할 수도 있으니까
이거 다 더하면 얼마지?
N^2 인데

10만 기준 N^2이면 괜찮은거 아닌가?
시간 5초까지 넉넉하게 주는데

---

https://donggoolosori.github.io/2020/10/15/boj-2263/
참고해서 해결

후위순위 마지막이 root인 점을 이용
이렇게 되면 TC O(N)이 가능하다.
