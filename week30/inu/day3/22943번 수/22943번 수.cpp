#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX = 98765;

int K, M;
int checked[10];
bool isComplex[MAX + 1];
bool isSumOfPrimes[MAX + 1];
bool isMultOfPrimes[MAX + 1];
vector<int> numbers;
vector<int> primes;

void getPrimes() {
	int m = MAX / 2;
	
	for (int i = 2; i <= m; i++) {
		for (int j = 2; i * j <= MAX; j++)
			isComplex[i * j] = true;
	}

	for (int i = 2; i <= MAX; i++)
		if (!isComplex[i])
			primes.push_back(i);
}

void comb(string number, int cnt) {
	if (cnt == K) {
		int n = stoi(number);
		numbers.push_back(n);
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (!checked[i]) {
			if (i == 0 && (int)number.length() == 0)
				continue;

			checked[i] = true;
			number.push_back(i + '0');

			comb(number, cnt + 1);

			checked[i] = false;
			number.pop_back();
		}
	}
}

int divideWithM(int n) {
	while (1) {
		if (n % M != 0) break;
		n /= M;
	}
	return n;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> K >> M;

	getPrimes();

	for (int i = 0; i < (int)primes.size() - 1; i++) {
		for (int j = i + 1; j < (int)primes.size(); j++) {
			int sum = primes[i] + primes[j];
			if (sum > MAX) break;
			isSumOfPrimes[sum] = true;
		}
	}

	for(int i = 0; i < (int)primes.size(); i++)
		for (int j = i; j < (int)primes.size(); j++) {
			long long mult = (long long)primes[i] * primes[j];
			if (mult > MAX) break;
			isMultOfPrimes[mult] = true;
		}

	comb("", 0);

	int cnt = 0;

	for (int number : numbers) {
		int divided = divideWithM(number);
		if (isSumOfPrimes[number] && isMultOfPrimes[divided])
			cnt++;
	}

	cout << cnt;

	return 0;
}