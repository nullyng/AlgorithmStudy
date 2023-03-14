#include <iostream>

using namespace std;

typedef long long ll;

int N, M;
int square[50][50];
ll answer = 0;

ll sum(int si, int ti, int sj, int tj) {
  ll result = 0;

  for(int i = si; i <= ti; i++)
    for(int j = sj; j <= tj; j++)
      result += square[i][j];
  
  return result;
}

void col_divide() {
  if(M < 3) return;

  ll a, b, c;

  for(int i = 0; i < M - 2; i++) {
    a = sum(0, N - 1, 0, i);

    for(int j = i + 1; j < M - 1; j++) {      
      b = sum(0, N - 1, i + 1, j);
      c = sum(0, N - 1, j + 1, M - 1);
      answer = max(answer, a * b * c);
    }
  }
}

void row_divide() {
  if(N < 3) return;

  ll a, b, c;

  for(int i = 0; i < N - 2; i++) {
    a = sum(0, i, 0, M - 1);

    for(int j = i + 1; j < N - 1; j++) {
      b = sum(i + 1, j, 0, M - 1);
      c = sum(j + 1, N - 1, 0, M - 1);
      answer = max(answer, a * b * c);
    }
  }
}

void col_square_divide() {
  if(M < 2 || N < 2) return;

  ll a, b, c;

  for(int i = 0; i < M - 1; i++) {
    for(int j = 0; j < N - 1; j++) {
      // ㅏ 모양
      a = sum(0, N - 1, 0, i);
      b = sum(0, j, i + 1, M - 1);
      c = sum(j + 1, N - 1, i + 1, M - 1);
      answer = max(answer, a * b * c);

      // ㅓ 모양
      a = sum(0, N - 1, M - 1 - i, M - 1);
      b = sum(0, j, 0, M - 2 - i);
      c = sum(j + 1, N - 1, 0, M - 2 - i);
      answer = max(answer, a * b * c);
    }
  }
}

void row_square_divide() {
  if(N < 2 || M < 2) return;

  ll a, b, c;

  for(int i = 0; i < N - 1; i++) {
    for(int j = 0; j < M - 1; j++) {
      // ㅜ 모양
      a = sum(0, i, 0, M - 1);
      b = sum(i + 1, N - 1, 0, j);
      c = sum(i + 1, N - 1, j + 1, M - 1);
      answer = max(answer, a * b * c);

      // ㅗ 모양
      a = sum(N - 1 - i, N - 1, 0, M - 1);
      b = sum(0, N - 2 - i, 0, j);
      c = sum(0, N - 2 - i, j + 1, M - 1);
      answer = max(answer, a * b * c);
    }
  }
}

int main() {
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

  col_divide();
  row_divide();
  col_square_divide();
  row_square_divide();

  cout << answer;

  return 0;
}