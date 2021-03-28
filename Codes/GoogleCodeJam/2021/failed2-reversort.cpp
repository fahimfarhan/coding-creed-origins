#include <bits/stdc++.h>
using namespace std;

int *L;
int N, kost;

void reverse(int start, int end) {
  int mid = start + ((end - start)>>1);

  for(int i=start; i<mid; i++) {
    swap( L[i], L[ (end-i+start) ] );
  }
}

void reverseSort() {
  for(int i=1; i<N; i++) {
    int j=i;
    for(int k=i; k<N; k++) {
      if(L[k] == i) { j = k;   break; }
    }

    reverse(i, j);
    kost+= (j - i + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int T;

  cin>>T;
  for(int t=1; t<=T; t++) {
    cin>>N;
    L = new int[N+1];

    for(int i=1; i<=N; i++) {
      cin>>L[i];
    }

    kost = 0;
    reverseSort();

    cout<<"Case #"<<t<<": "<<kost<<"\n";
    delete[] L;
  }

  return 0;
}