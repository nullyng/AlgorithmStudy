#include <iostream>
#include <string>
using ll = long long;
using namespace std;

string find(int n, ll y, ll x) {
  string result;

	for (int i = n - 1; i >= 0; i--) {
		ll cop = (1LL) << i;     
		if (y >= cop) { 
			y -= cop;

			if (x >= cop) {
				result += "4";
				x -= cop;
			}
			else result += "3";
		}
		else if (x >= cop) {
			x -= cop;
			result += "1";

		}
		else result += "2";
	}
	return result;
}

pair<ll, ll> get_coordinate(int q, string num, ll r, ll c) {
  int idx = 0;
  for (int i = q - 1; i >= 0; i--) {
    if(num[idx] == '1')
      c += ((1LL) << i);
    else if(num[idx] == '3')
      r += ((1LL << i));
    else if(num[idx] == '4') {
      c += ((1LL) << i);
      r += ((1LL) << i);
    }
    idx++;
  }

  return {r, c};
}

int main() {
  int q;
  string num;
  cin >> q >> num;

  pair<ll, ll> coordinate = get_coordinate(q, num, 0, 0);
  ll x, y;
  cin >> x >> y;
  coordinate.first -= y;
  coordinate.second += x;

  if(0 <= coordinate.first && coordinate.first <= ((1LL) << q) - 1 && 0 <= coordinate.second && coordinate.second <= ((1LL) << q) - 1)
    cout << find(q, coordinate.first, coordinate.second) << "\n";
  else
    cout << "-1\n";

  return 0;
}