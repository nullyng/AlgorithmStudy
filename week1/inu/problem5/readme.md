# 문제 개요

문제 : [괄호 회전하기](https://school.programmers.co.kr/learn/courses/30/lessons/76502?language=cpp)

문제 분류 : 문자열

# 문제 풀이

문자열의 시작 위치를 오른쪽으로 하나씩 옮기면서 올바른 괄호 문자열인지 검사한다.

```c++
for (int i = 0; i < len; i++) {
    bool flag = true;
    stack<char> st;

    for (int j = i; j < i + len; j++) {
      int idx = j % len;
      // ...
    }
}
```

`(`, `{`, `[`이면 스택에 넣고 `)`, `}`, `]` 이면 스택의 top에 있는 괄호와 짝이 맞는 괄호인지 확인한다.  
마지막에 스택이 비어있지 않으면 올바른 괄호 문자열이 아니기 때문에 이에 유의해야 한다.

처음에는 switch문으로 스택과 현재 인덱스의 괄호 문자를 비교했는데 여는 괄호에 맞는 닫는 괄호를 바로 알 수 있으면 좋을 것 같아서 `map`을 써서도 해보았다.

```c++
unordered_map<char, char> bracket;

bracket.insert({ '(', ')' });
bracket.insert({ '[', ']' });
bracket.insert({ '{', '}' });

for (int i = 0; i < len; i++) {
    bool flag = true;
    stack<char> st;

    for (int j = i; j < i + len; j++) {
      int idx = j % len;
      if (c == '(' || c == '[' || c == '{') {
        st.push(c);
      }
      else if (st.empty()
        || (*bracket.find(st.top())).second != c) {
        flag = false;
        break;
      }
      else {
        st.pop();
      }
    }
    // ...
}
```

소스 길이는 줄어들었지만 시간 차이가 꽤 나는 테스트케이스가 있었다.  
아마 `find`가 `map` 내부를 순회하면서 요소를 찾기 때문인 것 같다.  
`map`에 넣는 요소 갯수가 적어서 이렇게 해도 괜찮은데 많아진다면 이런 방식으로는 안될 것 같다.
