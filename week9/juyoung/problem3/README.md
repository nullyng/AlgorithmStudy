# 문제 개요

문제 : [게임 닉네임](https://www.acmicpc.net/problem/16934)

문제 분류 : 트라이

# 문제 풀이

트라이에 닉네임을 삽입하면서 해당 닉네임의 별칭을 반환받아 출력한다.

📌 **트라이의 삽입 함수 로직 변경**  
트라이에 `finish` 변수 대신 정수 타입의 `cnt`를 선언한다.  
이는 같은 닉네임으로 가입한 사람의 수를 저장하기 위해서이다.

삽입 함수의 인자로 현재 문자를 가리키는 `key`와 반환할 별칭 `result`를 넘긴다.  
또한 로직을 아래와 같이 변경한다.

`result`에는 현재 문자를 누적해서 저장한다.

```cpp
int curr = *key - 'a';
result += *key;
```

- 현재 문자가 문자열의 끝을 의미하는 `'\0'`이라면
  - `cnt`를 1 증가시킨다.
  - 증가시킨 `cnt`가 1이라면, `result`를 반환한다.
    - 현재 이 닉네임으로 가입한 사람이 1명이기 때문에 뒤에 수를 붙이지 않아도 된다.
  - 그렇지 않다면, `result`에 `cnt`를 붙여 반환한다.
    - 현재 이 닉네임으로 가입한 사람이 2명 이상이므로 뒤에 그 수를 붙인다.
- 현재 문자에 대한 노드가 `NULL`이라면
  - 새로운 노드를 할당하고 남은 문자에 대한 삽입 연산을 마저 한다.
  - **⭐️현재 문자에 대한 노드가 `NULL`이었던 지점의 `result`를 반환한다.⭐️**
- 위 두 가지에 해당하지 않는다면 남은 문자에 대한 삽입 연산을 마저 한다.

```cpp
string insert(char *key, string result) {
  if(*key == '\0') {
    if(++cnt == 1) return result;
    return result + to_string(cnt);
  }

  int curr = *key - 'a';
  result += *key;
  if(next[curr] == NULL) {
    next[curr] = new Trie();
    next[curr]->insert(key+1, result);
    return result;
  }

  return next[curr]->insert(key+1, result);
}
```

글만 보면 이해가 잘 안돼서 위 로직을 그림으로 표현했다.(⬇️)  
왼쪽부터 차례대로 `baekjoon`, `bakejoon`, `baekjoon`이 입력된 경우이다.

- 분홍색 글씨: 각 노드에서의 `result`
- 분홍색으로 칠해진 노드: 현재 문자에 대한 노드가 `NULL`이었던 지점
- 파란색 글씨: `cnt`

![IMG_A127DBB40E95-1](https://user-images.githubusercontent.com/57346428/215028456-f62dec1b-89f4-41ed-b91a-0f2aad2795de.jpeg)

1. `baekjoon` 입력 시
   - 처음 `result`는 첫 문자 `b`를 더한 `"b"`이다.
   - 아직 루트에 생성된 노드가 없으므로 첫 문자 `b`에 대한 노드를 생성한다.
   - 나머지 `"aekjoon"`에 대한 삽입 연산을 진행한다.
   - 마지막 문자까지 갔을 때 `cnt`를 1 증가시켜 `cnt`가 1이 된다.
   - 현재 문자에 대한 노드가 `NULL`이었던 지점의 `result`를 반환하므로 `"b"`를 반환한다.
2. `bakejoon` 입력 시
   - `b`, `a`에 대한 노드는 이미 생성되어 있다.
   - `k`에 대한 노드가 `NULL`이므로 이를 생성한다. (이때 `result`는 `"bak"`)
   - 나머지 `"ejoon"`에 대한 삽입 연산을 진행한다.
   - 현재 문자에 대한 노드가 `NULL`이었던 지점의 `result`인 `"bak"`를 반환한다.
3. `baekjoon` 입력 시
   - 모든 글자에 대한 노드가 이미 생성되어 있다.
   - 문자열의 끝에 도달했을 때 `cnt`를 1 증가시켜 `cnt`가 2가 된다.
   - `cnt`가 2 이상이므로 현재의 `result`인 `"baekjoon"`에 2를 합쳐 `"baekjoon2"`를 반환한다.
