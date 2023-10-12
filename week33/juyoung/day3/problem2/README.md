# 문제 개요

문제: [알약](https://www.acmicpc.net/problem/4811)

문제 분류: DP

# 문제 풀이

알약이 1개일 때부터 개수별로 경우의 수를 직접 구해보면서 점화식을 구하려고 했는데 잘 안돼서 [다른 사람 풀이](https://ghqls0210.tistory.com/209)를 참고했다.

- **`dp[w][h]`: 한조각이 `w`개, 반조각이 `h`개 있을 때 문자열의 경우의 수**

한조각을 W, 한조각짜리의 개수를 w, 반조각을 H, 반조각짜리의 개수를 h라고 할 때 다음의 세 가지로 나눌 수 있다.

1. W가 0개, H가 h개 있을 때(=한조각짜리가 없을 때)
   - 반조각짜리만 남아있다면 남은 경우는 H를 덧붙이는 하나의 경우밖에 없다.
   - 따라서 `dp[0][h]`는 전부 1로 초기화한다.
2. W가 w개, H가 0개 있을 때(=반조각짜리가 없을 때)
   - 한조각짜리만 남아있다면 한조각을 꺼내서 반으로 쪼개기 때문에 한조각은 1개 없어지고 반조각이 1개 생긴다.
   - 따라서 `dp[w][0]`은 `dp[w-1][1]`으로 초기화한다.
3. W가 w개, H가 h개 있을 때
   - 한조각짜리를 먹는다면 한조각은 1개 없어지고 반조각이 1개 생긴다. (`dp[w-1][h+1]`)
   - 반조각짜리를 먹는다면 반조각이 1개 없어진다. (`dp[w][h-1]`)
   - 이 두 경우를 합친 값이 `dp[w][h]`가 된다.