#include <iostream>

using namespace std;

typedef long long ll;

int N, M;
int square[50][50];
ll square_sum[50][50];
ll answer = 0;

void col_divide() {
  ll a, b, c;

  for(int i = 0; i < M - 2; i++) {
    a = square_sum[N - 1][i];

    for(int j = i + 1; j < M - 1; j++) {
      b = square_sum[N - 1][j] - a;
      c = square_sum[N - 1][M - 1] - square_sum[N - 1][j];
      answer = max(answer, a * b * c);
    }
  }
}

void row_divide() {
  ll a, b, c;

  for(int i = 0; i < N - 2; i++) {
    a = square_sum[i][M - 1];

    for(int j = i + 1; j < N - 1; j++) {
      b = square_sum[j][M - 1] - a;
      c = square_sum[N - 1][M - 1] - square_sum[j][M - 1];
      answer = max(answer, a * b * c);
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      char c;
      cin >> c;
      square[i][j] = c - '0';
    }
  }

  // 직사각형 누적합 구하기
  square_sum[0][0] = square[0][0];

  for(int i = 1; i < N; i++)
    square_sum[i][0] = square_sum[i - 1][0] + square[i][0];
  
  for(int j = 1; j < M; j++)
    square_sum[0][j] = square_sum[0][j - 1] + square[0][j];

  for(int i = 1; i < N; i++)
    for(int j = 1; j < M; j++)
      square_sum[i][j] = square[i][j] + square_sum[i - 1][j] + square_sum[i][j - 1] - square_sum[i - 1][j - 1];
  
  // || 모양
  col_divide();
  //  = 모양
  row_divide();
  
  for(int i = 0; i < N - 1; i++)
    for(int j = 0; j < M - 1; j++) {
      ll square1 = square_sum[i][j];
      ll square2 = square_sum[i][M - 1] - square1;
      ll square3 = square_sum[N - 1][j] - square1;
      ll square4 = square_sum[N - 1][M - 1] - (square1 + square2 + square3);

      // ㅏ 모양
      answer = max(answer, (square1 + square3) * square2 * square4);
      // ㅓ 모양
      answer = max(answer, square1 * square3 * (square2 + square4));
      // ㅜ 모양
      answer = max(answer, (square1 + square2) * square3 * square4);
      // ㅗ 모양
      answer = max(answer, (square3 + square4) * square1 * square2);
    }

  cout << answer;

  return 0; 
}