# 문제 개요

문제 : [지하철](https://www.acmicpc.net/problem/17940)

문제 분류 : 다익스트라

# 문제 풀이

다익스트라 이전에 환승 횟수가 그래프 가중치에 반영된다면 dist를 업데이트할 때 따로 환승 횟수를 고려할 필요가 없을 것 같았다.

지하철 간 이동 시간은 최대 1000이고 지하철역은 최대 1000개이므로 전체 이동시간의 최대값은 100만보다 작을 것이다.

따라서, 환승 횟수 1번당 1000만의 가중치를 준다면 최대 가중치는 1000만 \* 1000 = 100억에 100만을 더한 값이므로 long long 자료형으로 커버가 가능하다.

그래서 지하철 연결 정보를 받을 때, 두 역의 회사가 다른지 확인하고 다르면 1000만을 더해주고 다익스트라를 돌렸다.

환승 횟수는 dist[M] / 1000만이고 소요 시간은 dist[M] % 1000만이 된다.