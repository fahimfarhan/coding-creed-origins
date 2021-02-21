#include <bits/stdc++.h>
using namespace std;

int main() {
  string player1 = "Ashishgup";
  string player2 = "FastestFinger";

  int T, N, M;
  int oddDivisors;
  int zeroBitsCount;
  cin>>T;
  while(T--) {
    cin>>N;
    M = N;
    cout<<N<<" ";
    if(N == 1) {
      cout<<player2<<" case 1 \n";
    }else if( (N % 2) == 1) {
      cout<<player1<<" czse 2 \n";
    } else if(N == 2) {
      cout<<player2<<" case  \n";
    }
    
    else {

      oddDivisors = 0;
      for(int i=2; i*i <=N; i++) {
        if( (N%i) == 0) {
          int d1 = i;
          int d2 = N/i;

          if( (d1&1) == 1) {  oddDivisors++;   }
          if( (d1!=d2) && ((d2&1) == 1)) {  oddDivisors++;   } 
        }

        if(oddDivisors == 0) {       cout<<player2<<" case 3 \n"; }
        else if(oddDivisors > 1) {  cout<<player1<<" case 4 \n"; } 
        else{
          zeroBitsCount = 0;
          while( (N&1) == 0) {
            zeroBitsCount++;
            N = N >> 1;
          }

          if(zeroBitsCount == 1) {
            cout<<player2<<" case 5 \n";
          }else{  cout<<M<<" "<<player2<<" case 6 \n";  }
        }
      }
    }
  }
}