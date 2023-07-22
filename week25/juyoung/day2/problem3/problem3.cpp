#include <iostream>
#include <algorithm>
using namespace std;

int L, C;
char alphabet[16];
char selected[16];

void makePerm (int cnt, int idx) {
  if (cnt==L) {
      int mo, ja;
      mo = ja = 0;
      
      for (int i=0; i<L; i++) {
	    if (selected[i]=='a' || selected[i]=='e' || 
	    selected[i]=='i' || selected[i]=='o' || selected[i]=='u')
	        mo++;
	    else ja++;
      }
      
      if(mo<1 || ja<2) return;
      for(int i=0; i<L; i++) cout << selected[i];
      cout << "\n";
  }

    for (int i=idx; i<C; i++) {
        selected[cnt] = alphabet[i];
        makePerm (cnt+1, i+1);
	}
}

int main () {
    cin.tie (NULL);
    cout.tie (NULL);
    ios_base::sync_with_stdio (false);

    cin >> L >> C;
    for (int i=0; i<C; i++)
      cin >> alphabet[i];

    sort (alphabet, alphabet+C);
    makePerm (0, 0);

    return 0;
}