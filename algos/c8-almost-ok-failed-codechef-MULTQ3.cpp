#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE_M 100005

int a[MAX_SIZE_M] = {0};
int st[4*MAX_SIZE_M][3] = {0};
int lazy[4*MAX_SIZE_M] = {0};

inline void add(int si, int left, int right){
  st[si][0] = st[left][0] + st[right][0];
  st[si][1] = st[left][1] + st[right][1];
  st[si][2] = st[left][2] + st[right][2];
}

inline void builSegmentTree(int si, int ss, int se) {
  if(ss == se) {
    st[si][0] = 1;
    st[si][1] = 0;
    st[si][2] = 0;
    return;
  }

  int mid = ss + ((se - ss) >> 1);
  int left = si << 1;
  int right = left | 1;

  builSegmentTree(left, ss, mid);
  builSegmentTree(right, (mid+1), se);

  add(si, left, right);
}

inline void shift(int si) {
  int temp = st[si][2];
  st[si][2] = st[si][1];
  st[si][1] = st[si][0];
  st[si][0] = temp;
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

    if(ss != se) {
      int left = si << 1;
      int right = left | 1;

      lazy[left] += dx;
      lazy[right] += dx;
    }

    // todo: rotate dx times
    int r = dx % 3;
    rotate(si, r);
  }

  if((se < qs) || (qe < ss)) {  return 0; } // completely outside
  if((qs <= ss)||(se <= qs)) {
    return st[si][0];
  }

  int mid = ss + ((se - ss)>>1);
  int left = si << 1;
  int right = left | 1;

  int ql = query(left, ss, mid, qs, qe);
  int qr = query(right, (mid+1), se, qs, qe);

  return (ql+qr);
}

/*
--- ss1 --- se1 --- us --- ss --- se --- ue --- ss2 --- se2 ---
*/
inline void update(int si, int ss, int se, int us, int ue) {
  if(lazy[si] != 0) {
    int dx = lazy[si];
    lazy[si] = 0;

    if(ss != se) {
      // propagate
      int left = si << 1;
      int right = left | 1;
      lazy[left] += dx;
      lazy[right] += dx;
    }

    int r = dx % 3;
    rotate(si, r);
  }

  if((se < us) || (ue < ss)) {  return; }
  if( (us <= ss) && (se <= ue) ) {
    rotate(si, 1);
    if(ss != se) {
      int left = si << 1;
      int right = left | 1;

      lazy[left] += 1;
      lazy[right] += 1;
    }
    return;
  }

  int mid = ss + ((se - ss) >> 1);
  int left = si << 1;
  int right = left | 1;

  update(left, ss, mid, us, ue);
  update(right, (mid+1), se, us, ue);

  add(si, left, right);
}

int main() {
  int N, Q, M, A, B;
  cin>>N>>Q;

  builSegmentTree(1,1,N);

  while(Q--) {
    cin>>M>>A>>B;
    A = A + 1;
    B = B + 1;
    if(M == 0) {
      // update
      update(1, 1, N, A, B);
    }else{
      // query
      cout<<query(1, 1, N, A, B)<<"\n";
    }
  }
  return 0;
}