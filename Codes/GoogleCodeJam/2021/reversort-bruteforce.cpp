#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll N, kost;
ll *L;

inline void reverse(int a, int b) {
  int end = ((b-a) >> 1);
  for(int i=0; i<end; i++) {
    int temp = L[ (i + a) ];
    L[ (i+a) ] = L[ (b - i) ];
    L[ (b-i) ] = temp;
  }
}

inline void reverseSort() {
  for(int i=1; i<N; i++) {
    // if(L[i]!=i) {
      int j = 0;
      for(j=i; j <=N; j++) {
        if(L[j] == i) {
          break;  
        }
      }
      kost = kost + (j-i+1);
      reverse(i, j);
    // }
  }
}

inline void printer() {
  for(int i=1; i<=N; i++) {
    cout<<L[i]<<" ";
  }cout<<"\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int T;
  cin>>T;
  for(int t=1; t<=T; t++) {
    cin>>N;
    L = new ll[N+10];
    for(int i=1; i<=N; i++) {
      cin>>L[i];
    }

    kost = 0;
    reverseSort();

    // printer();
    cout<<"Case #"<<t<<": "<<kost<<"\n";

    delete[] L;
  }
  return 0;
}