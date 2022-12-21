#include <iostream>
#include <vector>

using namespace std;

int N;
long long B;
vector<int> binary;

void binary_num(long long k) {
	while (k != 0) {
		binary.push_back(k % 2);
		k /= 2;
	}
}

vector<vector<long long>> mult_matrix(vector<vector<long long>> A1, vector<vector<long long>> A2) {
	vector<vector<long long>> A(N, vector<long long>(N));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				A[i][j] += (A1[i][k] * A2[k][j]) % 1000;
				A[i][j] %= 1000;
			}
		}
	}

	return A;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> B;

	vector<vector<long long>> origin(N, vector<long long>(N));
	vector<vector<long long>> A(N, vector<long long>(N));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> origin[i][j];
			A[i][j] = origin[i][j];
		}
			
	binary_num(B);

	if (B > 1) {
		for (int i = (int)binary.size() - 2; i >= 0; i--) {
			if (binary[i] == 1) {
				vector<vector<long long>> square = mult_matrix(A, A);
				A = mult_matrix(square, origin);
			}
			else {
				A = mult_matrix(A, A);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << A[i][j] % 1000 << ' ';
		}
		cout << '\n';
	}

	return 0;
}