# 문제 개요

문제: [트리](https://www.acmicpc.net/problem/4256)

문제 분류: 분할정복, 재귀

# 문제 풀이

[다른 사람 풀이](https://kimjingo.tistory.com/114)를 참고했다.

전위 순회 결과의 첫 번째 노드는 트리 전체의 노드가 된다. 또한 이 노드를 중위 순회 결과에서 찾으면 그 값의 양쪽이 각각 루트 노드의 왼쪽 자식, 오른쪽 자식이 된다. 이러한 점을 활용하여 문제를 풀 수 있다.

즉, 전위 순회 결과를 바탕으로 루트를 찾고 중위 순회 결과에서 루트 노드의 왼쪽, 오른쪽 트리를 재귀적으로 탐색한다.

```cpp
void postorder(int start, int end, int pos) {
    for(int i=start; i<end; i++) {
        if(preorder[pos] == inorder[i]) {
            postorder(start, i, pos+1);
            postorder(i+1, end, pos+1+i-start);
            cout << preorder[pos] << " ";
        }
    }
}
```

- `start`: 중위 순회 결과에서 부분 트리의 시작 인덱스
- `end`: 중위 순회 결과에서 부분 트리의 끝 인덱스
- `pos`: 전위 순회 결과에서 루트의 위치
