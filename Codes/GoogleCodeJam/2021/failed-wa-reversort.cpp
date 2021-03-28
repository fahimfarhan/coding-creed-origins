#include <bits/stdc++.h>
using namespace std;

int N, kost;
int *L, *mp;

inline void initMp(int a, int b) {
  for(int i=a; i<=b; i++) {
    mp[L[i]] = i;
  }
}

inline void reverse(int a, int b) {
  int end = (b-a) >> 1;
  for(int i=0; i<end; i++) {
    int temp = L[ (i + a) ];
    L[ (i+a) ] = L[ (b - i) ];
    L[ (b-i) ] = temp;
  }
  initMp(a, b);
}

inline void reverseSort() {
  for(int i=1; i<N; i++) {
    int j = mp[i];
    kost = kost + (j-i+1);
    reverse(i, j);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int T;
  cin>>T;
  for(int t=1; t<=T; t++) {
    cin>>N;
    L = new int[N+10];
    mp = new int[N+10];
    for(int i=1; i<=N; i++) {
      cin>>L[i];
    }
    initMp(1, N);

    kost = 0;
    reverseSort();

    cout<<"Case #"<<t<<": "<<kost<<"\n";
    
    delete[] mp;
    delete[] L;
  }
  return 0;
}