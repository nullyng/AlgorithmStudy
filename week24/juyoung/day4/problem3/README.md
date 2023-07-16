# 문제 개요

문제 : [A와 B 2](https://www.acmicpc.net/problem/12919)

문제 분류 : 투포인터

# 문제 풀이

- 문자열의 뒤에 A를 추가한다.
- 문자열의 뒤에 B를 추가하고 문자열을 뒤집는다.

`S`에서 `T`를 만드는 것이 아니라 `T`에서 `S`로 조건에 맞춰 되돌린다. (A와 B 문제와 동일)  
따라서 위 조건에 맞춰 아래의 두 경우가 발생한다.

- `T`의 가장 끝 문자가 'A'이면 이를 제거한다.
- `T`의 첫 문자가 'B'이면 문자열을 뒤집고 마지막 문자 'B'를 제거한다.

하지만 가장 끝 문자가 'A'이면서 첫 문자가 'B'일 수 있다.  
그러므로 재귀를 통해 문자열에 대해 두 경우 모두를 살펴봐야 한다.

이 부분이 코드의 `check()` 부분이다.

```cpp
void check(string temp) {
  if(temp == S) {
      answer = 1;
      return;
  }

  int end = temp.length()-1;
  if(temp[end] == 'A') check(temp.substr(0, end));
  if(temp[0] == 'B') {
      reverse(temp.begin(), temp.end());
      check(temp.substr(0, end));
  }
}
```
