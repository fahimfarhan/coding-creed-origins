#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;  // limit for array size
int n;  // array size
//int t[2 * N];  // ORIGINAL
int *t;

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = max(t[p] , t[p^1]);
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = -15009;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res, t[l++]) ;
    if (r&1) res = max(res,t[--r]);
  }
  return res;
}

int main() {
  scanf("%d", &n);
  t = new int[n*4];

  for (int i = 0; i < n; ++i) scanf("%d", t + n + i);
  build();
  int m;
  while(m--){
      int x,y;
        cin>>x>>y;
      printf("%d\n", query(x, y));
  }
  // modify(0, 1);
  
  //cout<<"-----------\n";
  //for(int i=0; i<2*n; i++){ cout<<t[i]<<" ";  }
  //cout<<endl;
  if(!t)delete[] t;
  return 0;
}