#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int T, N, R, B;
  int kount = 0;
  string r, b;

  cin>>T;
  while(T--) {
    cin>>N;
    cin>>r;
    cin>>b;

    R = 0;
    B = 0;
    kount = 0;
    
    for(int i=0; i<N; i++) {
      R = r[i] - '0'; B = b[i] - '0';
      if(R > B) {
        kount++;
      } else if(R < B) {
        kount--;
      }
    }

    if(kount > 0) {
      cout<<"RED\n";
    } else if(kount < 0) {
      cout<<"BLUE\n";
    } else {
      cout<<"EQUAL\n";
    } 
  }
  return 0;
}