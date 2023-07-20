#include <iostream>
using namespace std;

int T, n;
int preorder[1001];
int inorder[1001];

void postorder(int start, int end, int pos) {
  for(int i=start; i<end; i++) {
      if(preorder[pos] == inorder[i]) {
          postorder(start, i, pos+1);
          postorder(i+1, end, pos+1+i-start);
          cout << preorder[pos] << " ";
      }
  }
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  
  cin >> T;
  while(T--) {
      
      cin >> n;
      for(int i=0; i<n; i++) cin >> preorder[i];
      for(int i=0; i<n; i++) cin >> inorder[i];
      
      postorder(0, n, 0);
      cout << "\n";
  }

  return 0;
}