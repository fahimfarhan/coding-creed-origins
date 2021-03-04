#include <bits/stdc++.h>
using namespace std;

#define ll long long int

#define N 100005

ll a[N];
ll segmentTree[4*N];

inline void build(int si, int ss, int se) {
  if(ss == se) {
    segmentTree[si] = a[ss];
  }

  int l = si << 1;
  int r = l | 1;
  int mid = ss + ((se - ss) >> 1);

  build(l, ss, mid);
  build(r, (mid+1), se);

  segmentTree[si] = min(segmentTree[l], segmentTree[r]); // someOperation
}


/*
  When in confusion, remember this graph!
--- --- ss1 --- se1 --- qs --- ss ---- se --- qe --- ss2 --- se2 --- ---
*/
inline int query(int si, int ss, int se, int qs, int qe) {
  if((qs > se) || (qe < ss)) {  return INT_MAX; }
  if((qs <= ss) && (se <= qe)) {
    return segmentTree[si];
  }

  int left = si << 1;
  int right = left | 1;

  int mid = ss + ((se - ss)>>1);

  int leftQuery = query(left, ss, mid, qs, qe);
  int rightQuery = query(right, (mid+1),se, qs, qe);

  segmentTree[si] = min(leftQuery, rightQuery);

  return segmentTree[si];
}

/**
 * assume: a[ui] = newValue; // already updated
 * so now we have to update the segment tree
*/
inline void pointUpdate(int si, int ss, int se, int ui) {
  // if( (ui < ss) || (ui > se)) {
  //   return;
  // }

  if(ss == se) {
    segmentTree[si] = a[ui];
    return;
  }
  int mid = ss + ((se - ss)>>1);
  int left = si << 1;
  int right = left | 1;

  if(ui <= mid) {
    pointUpdate(left, ss, mid, ui);
  }else{
    pointUpdate(right, (mid+1), se, ui);
  }

  segmentTree[si] = min(segmentTree[left], segmentTree[right]);
}

int main() {

  return 0;
}