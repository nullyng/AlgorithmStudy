# 문제 개요

문제 : [2800 괄호 제거](https://www.acmicpc.net/problem/2800)

문제 분류 : 문자열

# 문제 풀이

1. 처음 문자열을 입력 받고 나서 괄호쌍의 위치를 vector에 저장한다.
2. 각 괄호쌍을 식에 넣는 경우, 안 넣는 경우 2가지로 나눠서 모든 경우의 수를 구한다.

```c++
print[brackets[depth].first] = true;
print[brackets[depth].second] = true;
findExp(depth + 1);

print[brackets[depth].first] = false;
print[brackets[depth].second] = false;
findExp(depth + 1);
```

3. depth가 vector의 길이와 같아지면(==모든 괄호쌍의 포함 여부를 결정했으면) 문자열을 set에 넣는다.

- 사전순으로 정렬하는 것과 중복을 제거하기 위해 set 자료구조를 사용한다.
- 원래 문자열과 같은 경우는 set에 넣지 않는다.

4. iterator를 사용해서 set에 있는 요소들을 차례대로 출력한다.

```c++
set<string>::iterator iter;

for (iter = str_set.begin(); iter != str_set.end(); iter++) {
  cout << *iter << '\n';
}
```
