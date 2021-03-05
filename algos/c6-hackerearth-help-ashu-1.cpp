#include <bits/stdc++.h>

using namespace std;

#define ODD first
#define EVEN second
#define ll long long int
#define SIZEN 100005

int *a; //[SIZEN] = {0};
pair<int, int> *segmentTree; // [4*SIZEN];

inline void buildSegmentTree(int si, int ss, int se) {
  if(ss == se) {
    if((a[ss]&1) == 1) {
      segmentTree[si] = {1,0};
    }else{
      segmentTree[si] = {0,1};
    }
    return;
  }

  int left = si << 1;
  int right = left | 1;
  int mid = ss + ((se - ss)>>1);

  buildSegmentTree(left, ss, mid);
  buildSegmentTree(right, (mid+1), se);

  segmentTree[si].ODD = segmentTree[left].ODD + segmentTree[right].ODD;
  segmentTree[si].EVEN = segmentTree[left].EVEN + segmentTree[right].EVEN;
}

/*
--- ss1 --- se1 --- qs --- ss --- se --- qe --- ss2 --- se2 ---
*/
inline int query(int si, int ss, int se, int qs, int qe, int parity) {
  if((se < qs) || (qe < ss)) { // completely outside
    return 0;
  }
  if((qs <= ss) && (se <= qe)) { // completely inside
    if(parity) {
      return segmentTree[si].ODD;
    }else{
      return segmentTree[si].EVEN;
    }
  }

  int mid = ss + ((se-ss)>>1);
  int left = si << 1;
  int right = left | 1;

  int l = query(left, ss, mid, qs, qe, parity);
  int r = query(right, (mid+1), se, qs, qe, parity);

  return (l+r);
}

inline int getEven(int si, int ss, int se, int qs, int qe) {
  return query(si, ss, se, qs, qe, 0);
}

inline int getOdd(int si, int ss, int se, int qs, int qe) {
  return query(si, ss, se, qs, qe, 1);
}

inline void update(int si, int ss, int se, int key, int val) {
  if(ss == se) {
    int oldValue = a[key]; // old and new val have opposite parity. so
    if((oldValue & 1) == 1) {
      // toogle parity!
      segmentTree[si] = {0, 1};
    }else{
      segmentTree[si] = {1, 0};
    }
    a[key] = val;
    return;
  }

  int mid = ss + ((se-ss)>>1);
  int left = si << 1;
  int right = left | 1;

  if(key <= mid)   
    update(left, ss, mid, key, val);
  else  
    update(right, (mid+1), se, key, val);

  segmentTree[si].ODD = segmentTree[left].ODD + segmentTree[right].ODD;
  segmentTree[si].EVEN = segmentTree[left].EVEN + segmentTree[right].EVEN;
}

int main() {
  int N, Q, p, l, r;
  cin>>N;
  a = new int[N+1];
  segmentTree = new pair<int, int>[4*(N+1)];

  for(int i=1; i<=N; i++) {
    cin>>a[i];
  }

  buildSegmentTree(1,1,N);

  cin>>Q;
  while(Q--) {
    cin>>p>>l>>r;
    if(p == 0) {
      if( (a[l]&1) != (r&1)) {
        update(1,1,N,l,r);
      }
    }else if(p == 1) {
      cout<<getEven(1, 1, N, l, r)<<"\n";
    }else{
      cout<<getOdd(1, 1, N, l, r)<<"\n";
    }
  }

  delete[] segmentTree;
  delete[] a;
  
  return 0;
}