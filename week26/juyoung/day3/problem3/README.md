# 문제 개요

문제: [민균이의 계략](https://www.acmicpc.net/problem/11568)

문제 분류: 이분탐색

# 문제 풀이

최장 증가 부분 수열, 즉 LIS를 구하는 문제였다.

`lis` 배열에 최장 증가 부분 수열을 저장하는데, 이때 `lis[0]`은 카드 배열의 첫 번째 카드 값으로 초기화한다.  
또한 `j`가 `lis` 배열의 마지막 원소의 인덱스라고 할 때 카드를 하나씩 꺼내며 아래를 수행한다.

- 만약 현재 카드 값이 `lis[j]`보다 크다면 `lis[j+1]`에 카드 값을 저장하고 `j`를 1만큼 증가시킨다.
- 그렇지 않다면 `lis` 배열에서 **이분탐색**을 통해 현재 카드 값을 넣을 자리를 찾아 넣는다.

# 알게 된 점

## LIS 알고리즘

### 1. DP

```cpp
for (int k = 0; k < n; k++){
	lis[k] = 1;
    for (int i = 0; i < k; i++){
        if(arr[i] < arr[k]){
            lis[k] = max(lis[k], lis[i] + 1);
        }
    }
}
```

주어진 배열에서 인덱스(`k`)를 한 칸씩 늘려가면서 내부 반복문으로 `k`보다 작은 인덱스들을 하나씩 살펴 보면서 `arr[i]` < `arr[k]`인 것이 있을 경우 `lis[k]`를 업데이트한다.

이렇게 DP를 이용하여 구할 경우 시간 복잡도가 O(n^2)이다. 더 효율적으로 풀이하기 위해서는 이분탐색을 사용할 수 있다.

### 2. 이분탐색

```cpp
#include <iostream>
using namespace std;

int N;
int arr[1001];
int lis[1001];

int binary_search(int left, int right, int target) {
  int mid;

  while(left < right) {
    mid = (left + right) / 2;

    if(lis[mid] < target) left = mid + 1;
    else right = mid;
  }

  return right;
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];

  int j = 0;
  lis[0] = arr[0];
  int i = 1;

  while(i<N) {
    if(lis[j] < arr[i]) {
      // lis에서 가장 큰 값보다 현재 배열 값이 더 크면
      // lis 배열 끝에 현재 배열 값을 추가한다.
      lis[j + 1] = arr[i];
      j++;
    } else {
      // 그렇지 않다면 이분탐색을 통해 알맞은 위치를 찾아 넣는다.
      int idx = binary_search(0, j, arr[i]);
      lis[idx] = arr[i];
    }
    i++;
  }

  cout << j + 1 << "\n";
  return 0;
}
```

이분탐색의 경우 시간 복잡도가 O(log n)이므로 위와 같이 LIS를 구할 때 시간 복잡도는 O(nlog n)가 된다.

## 참고

🔗 [LIS 알고리즘](https://chanhuiseok.github.io/posts/algo-49/)
