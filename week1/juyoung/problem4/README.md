# 문제 개요

문제 : [1013 Contact](https://www.acmicpc.net/problem/1013)

문제 분류 : 문자열, 정규 표현식

# 문제 풀이

정규 표현식을 사용하여 풀 수 있었다.

- `#include <regex>`
- **`regex re("정규 표현식")`** → regex 인스턴스 생성
- **`regex_match(str, re)`** → 문자열과 정규 표현식 비교

## 정규 표현식

### :mag_right: Quantifiers - \*+? and {}

**abc\***  
ab 그리고 **0개 이상의 c**를 포함한 문자열과 매칭

**abc+**  
ab 그리고 **1개 이상의 c**를 포함

**abc?**  
ab 그리고 **0개 또는 1개의 c**를 포함

**abc{2}**  
ab 그리고 **2개의 c**를 포함

**abc{2,}**  
ab 그리고 **2개 이상의 c**를 포함

**abc{2,5}**  
ab 그리고 **2개 이상 5개 이하의 c**를 포함

**a(bc)\***  
a 그리고 **0개 이상의 bc**를 포함

**a(bc){2,5}**  
a 그리고 **2개 이상 5개 이하의 bc**를 포함

### :mag_right: OR operator - | or []

**a(b|c)**  
a 그리고 **b 또는 c를 포함**

**a[bc]**  
위와 동일
