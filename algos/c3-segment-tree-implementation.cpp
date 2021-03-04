#include <bits/stdc++.h>
using namespace std;

#define N 100
int a[N];
int segmentTree[4*N];


int someOperation(int left, int right) {
  return min(left , right); // or sum, max, xor, ...
}

void buildSegmentTree(int index, int start, int end) {
  if(start == end) {
    segmentTree[index] = a[start];
    return;
  }

  int mid = start + ((end - start)>>1);
  int left = index << 1;
  int right = left | 1;

  buildSegmentTree(left, start, mid);
  buildSegmentTree(right, (mid+1), end);

  segmentTree[index] = someOperation(segmentTree[left], segmentTree[right]);
}


/*
  When in confusion, remember this graph!
--- --- ss1 --- se1 --- qs --- ss ---- se --- qe --- ss2 --- se2 --- ---
*/
int query(int si, int ss, int se, int qs, int qe) {
  if((ss > qe) || (se < qs)) {  return INT_MAX; } // case: completely outside

  if((ss >= qs) && (se <= qe)) { 
    return segmentTree[si];  // case: completely inside
  }


  int mid = ss + ((se - ss)>>1);
  int l = si << 1;
  int r = l | 1;
  int left = query(l, ss, mid, qs, qe);
  int right = (r, (mid+1), se, qs, qe);

  return someOperation(left, right);
}

int main(){

  return 0;
}