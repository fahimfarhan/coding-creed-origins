#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int m[5][5];

  for(int i=0; i<5; i++) {
    for(int j=0; j<5; j++) {
      cin>>m[i][j];
    }
  }

  int x,y;

  for(int i=0; i<5; i++) {
    for(int j=0; j<5; j++) {
      if(m[i][j] == 1) {
        x = i; y = j; break;
      }
    }
  }

  int numberOfMoves = abs(x - 2) + abs(y - 2);

  cout<<numberOfMoves<<"\n";

  return 0;
}