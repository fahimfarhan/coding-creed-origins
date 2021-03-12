#include <bits/stdc++.h>
using namespace std;

#define SIZE_N 100005

int a[SIZE_N] = {0};
int segmentTree[(4*SIZE_N)][3] = {0};
int lazy[(4*SIZE_N)] = {0};

inline void buildSegmentTree(int si, int ss, int se) {
  if(ss == se) {
    segmentTree[si][0] = 1;
    segmentTree[si][1] = 0;
    segmentTree[si][2] = 0;

    return;
  }

  int mid = ss + ((se - ss)>>1);
  int left = si << 1;
  int right = left | 1;

  buildSegmentTree(left, ss, mid);
  buildSegmentTree(right, (mid+1), se);

  segmentTree[si][0] = segmentTree[left][0] + segmentTree[right][0];
  segmentTree[si][1] = segmentTree[left][1] + segmentTree[right][1];
  segmentTree[si][2] = segmentTree[left][2] + segmentTree[right][2];
}

inline void shift(int si) {
    int temp = segmentTree[si][2];
    segmentTree[si][2] = segmentTree[si][1];
    segmentTree[si][1] = segmentTree[si][0];
    segmentTree[si][0] = temp;
}

inline void rotate(int si, int r) {
  for(int i=0; i<r; i++) {
    shift(si);
  }
}

/*
--- ss1 --- se1 --- qs --- ss --- se --- qe --- ss2 --- se2 ---
*/
inline int query(int si, int ss, int se, int qs, int qe) {
  if(lazy[si]!=0) {
    int dx = lazy[si];
    lazy[si] = 0;

    if(ss!=se) {
      int left = si << 1;
      int right = left | 1;

      lazy[left] = dx;
      lazy[right] = dx;
    }
    
    int r = (dx % 3);
    rotate(si, r);
  }

  if((se < qs) || (qe < ss) ) { return 0; }  // case: out of range
  if((qs <= ss) && (se <= qe)) { // case: completely inside the range
    return segmentTree[si][0];
  }

  int mid = ss + ((se - ss)>>1);
  int left = si << 1;
  int right = left | 1;

  int ql = query(left, si, mid, qs, qe);
  int qr = query(right, (mid+1), se, qs, qe);

  return (ql + qr);
}

inline void update(int si, int ss, int se, int us, int ue, int val) {
  if(lazy[si]!=0) {
    int dx = lazy[si];
    lazy[si] = 0;

    if(ss!=se) {
      int left = si << 1;
      int right = left | 1;

      lazy[left] += dx;
      lazy[right] += dx;
    }
    
    int r = (dx % 3);
    rotate(si, r);
  }

  if((se < us) || (ue < ss) ) { return; }  // case: out of range
  if((us <= ss) && (se <= ue)) { // case: completely inside the range
    
    rotate(si, val);

    if(ss != se) {
      int left = si << 1;
      int right = left | 1;

      lazy[left] += val;
      lazy[right] += val;
    }
    
    //lazy[si] += val;
    return; // segmentTree[si][0];
  }

  int mid = ss + ((se - ss)>>1);
  int left = si << 1;
  int right = left | 1;

  update(left, ss, mid, us, ue, val);
  update(right, (mid+1), se, us, ue, val);

  segmentTree[si][0] = segmentTree[left][0] + segmentTree[right][0];
  segmentTree[si][1] = segmentTree[left][1] + segmentTree[right][1];
  segmentTree[si][2] = segmentTree[left][2] + segmentTree[right][2];
}

int main() {
  int N, Q, p, l, r;
  cin>>N>>Q;

  // for(int i=1; i<=N; i++) {
  //   cin>>a[i];
  // }

  buildSegmentTree(1,1,N);

  while(Q--) {
    cin>>p>>l>>r;
    l+=1; r+=1;
    if(p == 0) {
      //update()
      update(1,1,N, l, r, 1);
    }else if(p == 1) {
      // query
      cout<<query(1, 1, N, l, r)<<"\n";
    }
  }
  return 0;
}