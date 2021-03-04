#include <bits/stdc++.h>
using namespace std;

#define ll long long int 

ll *a;
ll *segmentTree;  // kount of odd numbers
int N;

inline void buildSegmentTree(int si, int ss, int se) {
  if(ss == se) {
    segmentTree[si] = (a[ss]&1);
    return;
  }

  int mid = ss + ((se - ss)>>1);
  int left = si << 1;
  int right = left | 1;

  buildSegmentTree(left, ss, mid);
  buildSegmentTree(right, (mid+1), se);

  segmentTree[si] = segmentTree[left] + segmentTree[right];
}

/*
 ss1   se1  qs  ss  se  qe  ss2  se2 
*/
inline int queryOddNumbers(int si, int ss, int se, int qs, int qe) {
  if( (se < qs) || (qe < ss)) {
    return 0;
  }

  if( (qs <= ss) && (se <= qe)) {
    return segmentTree[si];
  }

  int mid = ss + ((se - ss)>>1);
  int left = si << 1;
  int right = left | 1;

  int queryLeft = queryOddNumbers(left, ss, mid, qs, qe);
  int quertRIght = queryOddNumbers(right, (mid+1), se, qs, qe);

  return quertRIght + queryLeft;
}

inline void update(int si, int ss, int se, int ui) {
  if(ss == se) {
    segmentTree[si] = (a[ss]&1);
    return;
  }

  int mid = ss + ((se - ss) >> 1);
  int l = si << 1;
  int r = l | 1;
  if(ui <= mid) {
    update(l, ss, mid, ui);
  }else{
    update(r, (mid+1), se, ui);
  }

  segmentTree[si] = segmentTree[l]+segmentTree[r];
}

int main(){
  cin>>N;

  a = new ll[N+1];
  segmentTree = new ll[4*(N+1)];

  for(int i=1; i<=N; i++) {
    cin>>a[i];
  }

  buildSegmentTree(1,1,N);

  // for(int i=0; i<4*N+4; i++) {
  //   cerr<<"s["<<i<<"] = "<<segmentTree[i]<<"\n";
  // }

  int Q, op, x, y;
  int oddNumbersKount, evenNumberKount;
  cin>>Q;
  while(Q--) {
    cin>>op>>x>>y;
    if(op == 0) {
      a[x] = y;
      update(1,1,N,y);
// cerr<<"-----------------------------\n";
//         for(int i=0; i<4*N+4; i++) {
//     cerr<<"s["<<i<<"] = "<<segmentTree[i]<<"\n";
//   }
    }else if(op == 1) {
      oddNumbersKount = queryOddNumbers(1,1,N, x, y);
      evenNumberKount = (y-x+1) - oddNumbersKount;

      cout<<evenNumberKount<<"\n";
    }else{
      oddNumbersKount = queryOddNumbers(1,1,N, x, y);
      cout<<oddNumbersKount<<"\n";
    }
  }

  delete[] a;
  delete[] segmentTree;
  return 0;
}