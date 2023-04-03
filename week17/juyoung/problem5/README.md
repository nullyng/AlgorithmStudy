# 문제 개요

문제 : [문자열 압축](https://school.programmers.co.kr/learn/courses/30/lessons/60057)

문제 분류 : 문자열

# 문제 풀이

문자열을 1~문자열의 길이/2개 단위로 자르면서 압축했을 때 가장 짧은 문자열의 길이를 찾는다.  
(문자열의 길이/2까지 자르는 이유는 압축하려는 문자열의 최대 길이가 문자열의 절반이기 때문이다.)

`len` = 자를 문자열의 길이  
`temp` = 현재 자른 문자열  
`cnt` = 현재 문자열로 압축된 개수  
`comp` = `len`을 단위로 압축했을 때 압축된 문자열의 길이
`answer` = 가장 짧은 압축 문자열의 길이

1. `temp`에 주어진 문자열의 0부터 `len`까지 자른 문자열을 저장한다.
2. 그 이후부터 `len`만큼 문자열을 자르며 `temp`와 비교한다.
   - 만약 `temp`와 같다면 `cnt`를 증가시킨다.
   - 그렇지 않다면 `temp`로는 더이상 압축할 수 없다는 의미이므로
     1. 만약 현재 압축된 개수가 2개 이상인 경우 `comp`에 그 개수의 자릿수를 더한다.
     2. `comp`에 자른 문자열의 길이를 더한다.
     3. `temp`에 현재 위치에서 `len`만큼 자른 새 문자열을 저장한다.
     4. `cnt`를 1로 초기화한다.
3. 2번 과정이 끝난 후 마지막에 더해지지 않은 문자열의 길이를 더하는 작업을 한다.
   - 만약 `cnt`가 2 이상이면 압축된 것이므로 `comp`에 `cnt`의 자릿수를 더한다.
   - `comp`에 `temp`의 길이를 더한다.
4. `answer`와 `comp` 중 작은 값을 `answer`에 저장한다.
5. `len`을 1만큼 증가시킨다.