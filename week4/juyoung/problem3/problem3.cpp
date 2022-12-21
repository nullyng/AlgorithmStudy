#include <iostream>
using namespace std;

int N;
long long B;
long long A[5][5];
long long answer[5][5];

void matrix_square(long long mat1[5][5], long long mat2[5][5]) {
  long long temp[5][5] = {0};

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++)
        temp[i][j] += mat1[i][k] * mat2[k][j];
      temp[i][j] %= 1000;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      mat1[i][j] = temp[i][j];
    }
  }
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> B;
  for(int i=0; i < N; i++) {
    for (int j = 0; j < N; j++)
      cin >> A[i][j];
    answer[i][i] = 1;
  }

  while (B > 0) {
    if (B % 2 == 1)
      matrix_square(answer, A);
    matrix_square(A, A);
    B /= 2;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      cout << answer[i][j] << " ";
    cout << "\n";
  }

  return 0;
}