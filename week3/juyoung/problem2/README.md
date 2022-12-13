# 문제 개요

문제 : [개똥벌레](https://www.acmicpc.net/problem/3020)

문제 분류 : 이분탐색

# 문제 풀이

1. 석순과 종유석을 서로 다른 배열에 입력 받고 오름차순 정렬 한다.
2. 첫 번째 구간부터 `H`번째 구간까지 차례대로 이분탐색 한다.

이분탐색 시 아래의 과정을 반복한다.  
(`h` == 구간, `answer` == 장애물의 최솟값, `count` == 그러한 구간)

1. `h`보다 크거나 같은 석순의 개수를 구한다.
   - `lower_bound()` 사용
2. `H-h`보다 큰 종유석의 개수를 구한다.
   - `upper_bound()` 사용
   - 종유석은 거꾸로 매달려 있으므로 `h`번째 구간의 장애물이 되려면 `H-h`보다 커야 한다.
3. 석순과 종유석 개수의 합에 따라 `answer`와 `count`를 업데이트 한다.
   - `answer`보다 작다면 `answer`를 업데이트 하고 `count`를 1로 초기화 한다.
   - `answer`와 같다면 `count`를 증가시킨다.
4. `answer`와 `count`를 출력한다.

예제 입력 2에 대한 풀이 과정을 그림으로 나타내면 아래와 같다.

![IMG_A67BAA5E5145-1](https://user-images.githubusercontent.com/57346428/207216042-99984638-24bf-494a-b51c-4c0d900d8ec8.jpeg)
![IMG_E788BAE616E8-1](https://user-images.githubusercontent.com/57346428/207216060-913876ff-c76f-49f8-9cb4-f852955cf99c.jpeg)

# 알게 된 점

## lower_bound, upper_bound

- :warning: 주의사항
  - 탐색을 진행할 배열 혹은 벡터는 **오름차순으로 정렬**되어 있어야 한다.
  - **반환형이 iterator**이기 때문에 실제로 몇 번째 인덱스인지 알고 싶다면, 배열이나 벡터의 주소를 빼줘야 한다.

1. **lower_bound**
   - 찾으려는 key 값보다 **같거나 큰 숫자**가 배열의 몇 번째에서 처음 등장하는지 찾을 때 사용한다.
   ```cpp
   // arr에서 3 이상의 숫자가 처음으로 나오는 인덱스 번호 반환
   int arr[5] = { 1, 2, 3, 4, 5 };
   int idx = lower_bound(arr, arr+5, 3) - arr;
   ```
2. **upper_bound**
   - 찾으려는 key 값을 **초과하는 숫자**가 배열의 몇 번째에서 처음 등장하는지 찾을 때 사용한다.
   ```cpp
   // arr에서 3을 초과하는 숫자가 처음으로 나오는 인덱스 번호 반환
   int arr[5] = { 1, 2, 3, 4, 5 };
   int idx = upper_bound(arr, arr+5, 3) - arr;
   ```
