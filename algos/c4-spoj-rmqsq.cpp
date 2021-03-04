#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define N 100005

ll a[N];
ll segmentTree[4*N];

inline void buildSegmentTree(int si, int ss, int se) {
  if(ss > se) { return; }
  
  if(ss == se) {
    segmentTree[si] = a[ss];
    return;
  }

  int mid = ss + ((se - ss) >> 1);
  int left = si<<1;
  int right = left|1;

  buildSegmentTree(left, ss, mid);
  buildSegmentTree(right, (mid+1), se);

  segmentTree[si] = min(segmentTree[left], segmentTree[right]); // someOperation
}

/*
  When in confusion, remember this graph!
--- --- ss1 --- se1 --- qs --- ss ---- se --- qe --- ss2 --- se2 --- ---
*/
inline int query(int si, int ss, int se, int qs, int qe) {  
  if((ss > qe) || (se < qs)) {  return INT_MAX; } // case: completely outside

  if((ss >= qs) && (se <= qe)) { 
    return segmentTree[si];  // case: completely inside
  }

  int left = si << 1;
  int right = left | 1;

  int mid = ss + ((se - ss) >> 1);

  int leftQuery = query(left, ss, mid, qs, qe);
  int rightQuery = query(right, (mid+1), se, qs, qe);
  
  return min(leftQuery, rightQuery); // someOperation
}


int main() {

  ll T, n;
  // cin>>T;
  // while (T--)  {
    /* code */
    cin>>n;
    for(int i=1; i<=n; i++) {
      cin>>a[i];
    }

    // for(int i=0; i<=4*n; i++) { segmentTree[i] = INT_MAX; }

    buildSegmentTree(1, 1, n);

    // for(int i=0; i<4*n; i++) {
    //   cerr<<"s["<<i<<"] = "<<segmentTree[i]<<"\n";
    // }

    int Q, i, j;
    cin>>Q;
    while (Q--){
      /* code */
      cin>>i>>j;
      i = i + 1;
      j = j + 1;

      cout<<query(1,1,n,i,j)<<"\n";
    }
    
  // }
  

  return 0;
}