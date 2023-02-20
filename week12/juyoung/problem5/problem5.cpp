#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
int alphabet[26];
int answer;

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for (int i = 0; i < N; i++) {
    string str;
    cin >> str;

    int num = 1;
    for (int j = str.length() - 1; j >= 0; j--) {
      int idx = str[j] - 'A';
      alphabet[idx] += num;
      num *= 10;
    }
  }

  sort(alphabet, alphabet + 26, greater<int>());

  for (int i = 0; i < 26; i++)
    answer += alphabet[i] * (9 - i);

  cout << answer << "\n";
  return 0;
}