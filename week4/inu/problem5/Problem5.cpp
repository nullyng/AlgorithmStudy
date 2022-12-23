#include <iostream>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	multiset<int> card;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int card_size;
		cin >> card_size;
		card.insert(card_size);
	}

	if (N == 1) {
		cout << 0;
		return 0;
	}

	int total_sum = 0;

	while ((int)card.size() != 1) {
		multiset<int>::iterator first = card.begin();
		multiset<int>::iterator second = ++first;
		first = card.begin();
		
		int sum = *first + *second;
		total_sum += sum;

		card.erase(first);
		card.erase(second);

		card.insert(sum);
	}

	cout << total_sum;

	return 0;
}