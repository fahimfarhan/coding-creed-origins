#include <bits/stdc++.h>
using namespace std;

// #define ll long long int

int N, Q;
int *a;
int *st;
int *start;
map<int,int> countMp;


inline void build(int si, int ss, int se) {
  if(ss == se) {
    st[si] = a[si];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin>>N>>Q;
  a = new int[N+5];
  st = new int[((N+5)<<2)];
  start = new int[N+5];

  for(int i=1; i<=N; i++) { cin>>a[i];  }




  delete[] start;
  delete[] st;
  delete[] a;
  return 0;
}