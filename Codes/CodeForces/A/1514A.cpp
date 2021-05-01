#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  // int isSquare[10001];
  bitset<10001> isSquare(0);
 
  for(int i=1; i<10001; i++) {
    int j = (int)sqrt(i);
    if( (j*j) == i) {
      isSquare[i] = 1;
    }else{
      isSquare[i] = 0;
    }
  }
 
  int T, N, *a;
  cin>>T;
  while(T--) {
    cin>>N;
    a = new int[N+1];
    for(int i=0; i<N; i++) {
      cin>>a[i];
    }
 
    bool isPossible = false;
    for(int i=0; i<N; i++) {
      if(isSquare[a[i]] == 0) {
        isPossible = true; break;
      }
    }
 
    if(isPossible) {
      cout<<"YES\n";
    }else{
      cout<<"NO\n";
    }
 
    delete[] a;
  }
  return 0;
}