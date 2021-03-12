#include <bits/stdc++.h>

using namespace std;

#define SIZE_N 100005

int a[SIZE_N] = {0};
int segmentTree[SIZE_N] = {0};
int lazy[SIZE_N] = {0};
 
inline void buildSegmentTree(int si, int ss, int se) {
  if(ss == se) {
    segmentTree[si] = a[ss];
    return;
  }

  int mid = ss + ((se - ss) >> 1);
  int left = si << 1;
  int right = left | 1;

  buildSegmentTree(left, ss, mid);
  buildSegmentTree(right, (mid+1), se);
}

/*
--- ss1 --- se1 --- qs --- ss --- se --- qe --- ss2 --- se2 ---
*/
inline int query(int si, int ss, int se, int qs, int qe) {
  if(lazy[si]!=0) {
    int dx = lazy[si];
    lazy[si] = 0;

    segmentTree[si] += dx * (se - ss + 1);

    if(ss != se) {
      lazy[(si<<1)] += dx;
      lazy[((si<<1)|1)] += dx;
    }
  }

  if((se < qs) || (qe < ss)) {  return 0; }
  if((qs <= ss) && (se <= qe)) {
    return segmentTree[si];
  }

  int mid = ss + ((se-ss)>>1);
  int left = si << 1;
  int right = left | 1;

  int qleft = query(left, ss, mid, qs, qe);
  int qright = query(right, (mid+1), se, qs, qe);

  return (qleft + qright);
}

/*
--- ss1 --- se1 --- us --- ss --- se --- ue --- ss2 --- se2 ---
*/
inline void update(int si, int ss, int se, int us, int ue, int value) {
  if(lazy[si]!=0) {
    int dx = lazy[si];
    lazy[si] = 0;
    segmentTree[si] += dx * (se - ss + 1);

    if(ss != se) {
      lazy[(si << 1)] += dx;  
      lazy[((si << 1)|1)] += dx;
    }
  }

  if((se < us) || (ue < ss)) {  return; }
  
  if( (us <= ss) && (se <= ue)) {
    int dx = (se - ss + 1) * value;
    segmentTree[si] += dx;

    if(ss != se) {
      lazy[(si << 1)] += value;  
      lazy[((si << 1)|1)] += value;
    }
    return;
  }

  int mid = ss + ((se - ss) >> 1);
  
  int left = si << 1;
  int right = left | 1;

  update(left, ss, mid, us, ue, value);
  update(right, (mid+1), se, us, ue, value);

  segmentTree[si] = segmentTree[left] + segmentTree[right];
}

int main() {

  return 0;
}