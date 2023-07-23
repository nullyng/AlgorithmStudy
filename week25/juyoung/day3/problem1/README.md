# 문제 개요

문제: [서로소 평균](https://www.acmicpc.net/problem/21920)

문제 분류: 수학, 유클리드 호제법

# 문제 풀이

두 수가 서로소이려면 두 수의 최대공약수가 1이어야 한다.  
따라서 유클리드 호제법을 통해 `X`와 최대공약수가 1인 수만 구해서 평균을 구한다.

# 알게 된 점

## 유클리드 호제법

주어진 두 수 사이에 존재하는 최대공약수(GCD)를 구하는 알고리즘이다.

a, b가 주어지고 더 큰 값이 a라고 했을 때  
a를 b로 나눈 나머지가 0이 아니면 a와 b를 바꾼 뒤 나머지가 0일 때까지 계속 반복한다.  
a를 b로 나눈 나머지가 0일 때! b가 최대공약수가 된다.

```cpp
int gcd(int a, int b) {
  int temp;

  // 더 큰 수를 a에 저장한다.
  if(a < b) {
    temp = a;
    a = b;
    b = temp;
  }

  int rest;
  // b가 0일 때 a의 값이 최대공약수가 된다.
  while(b != 0) {
    rest = a % b;
    a = b;
    b = rest;
  }

  return a;
}
```

## 참고

🔗 [유클리드 호제법](https://wotres.tistory.com/entry/%EC%9C%A0%ED%81%B4%EB%A6%AC%EB%93%9C-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98GCD-c-%EC%BD%94%EB%93%9C#google_vignette)
