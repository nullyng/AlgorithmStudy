# 문제 개요

문제 : [1038 감소하는 수](https://www.acmicpc.net/problem/1038)

문제 분류 : 백트래킹

# 문제 풀이

감소하는 수의 최대값은 9876543210으로 최대 한 자리수부터 열 자리수까지 존재한다.

따라서, 숫자의 길이가 1인 것부터 10인 것까지 차례대로 감소하는 수를 구하면 되고 각 숫자의 길이마다 앞자리가 0 ~ 9인 경우를 각각 구한다.

숫자를 더 쉽게 구하기 위해 string형 변수에 숫자 문자를 하나씩 넣으면서 계산했다.

```c++
void decrease(string s, char end, int len) {
	if (end < '0' || end > '9') return;

	if ((int)s.size() == len) {
		v.push_back(s);
		return;
	}

	for (char c = '0'; c < end; c++) {
		s += c;
		decrease(s, c, len);
		s.pop_back();
	}
}
```
