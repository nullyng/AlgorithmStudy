약수 구하기.
1 ~ N 까지 숫자의 약수를 각각 구해서
누적합으로 처리하면 될 것 같음.

1. 에라토스테네스의 체로 100만까지 소수 다 구한다.
2. 100만까지의 소수 벡터를 가지고 있음.
3. 그걸 2차원 배열로 100만 \* 소수벡터?

약수 구하는 시간복잡도 O(N^(1/2))
100만 \* 1000
쪼매 힘든데.

그냥 1부터 함 생각해보자

1 = 1
2 = 1, 2
3 = 1, 3
4 = 1, 2, 4
5 = 1, 5
6 = 1, 2, 3, 6
7 = 1, 7
8 = 1, 2, 4, 8
9 = 1, 3, 9
10 = 1, 2, 5, 10
11 = 1, 11
12 = 1, 2, 3, 4, 6, 12