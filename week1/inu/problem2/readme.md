# 문제 개요

문제 : [9935 문자열 폭발](https://www.acmicpc.net/problem/9935)

문제 분류 : 문자열

# 문제 풀이

1. 원본 문자열의 문자를 하나씩 `remain`에 넣는다.
2. `remain`의 길이가 폭발 문자열의 길이보다 크거나 같아지면 `remain`에 폭발 문자열이 있는지 확인한다.

```c++
  bool flag = true;
  int len = (int)remain.length();

  for (int j = 0; j < word_len; j++) {
    if (remain[len - word_len + j] != word[j]) {
      flag = false;
      break;
    }
  }
```

3. 폭발 문자열이 있으면 `remain`에서 폭발 문자열의 길이 만큼 pop을 한다.

```c++
  if (flag) {
    int cnt = word_len;

    while (cnt) {
      remain.pop_back();
      cnt--;
    }
  }
```
