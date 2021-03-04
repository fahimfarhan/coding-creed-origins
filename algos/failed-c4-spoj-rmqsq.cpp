#include <bits/stdc++.h>
using namespace std;

#define N 100005
int a[N];
int segemntTree[4*N];

int someOperation(const int& left,const int& right) {
  return min(left, right);
}

void buildSegmentTree(int si, int ss, int se) {
  // cerr<<"debug bst 1 "<<si<<" "<<ss<<" "<<se<<"\n";
  // if(si >= 4*N) {  return; }

  if(ss == se) {
    segemntTree[si] = a[ss]; // = a[se];
    return;
  }

  int mid = ss + ((se - ss) >> 1);
  int left = si << 1;
  int right = left | 1;

  buildSegmentTree(left, ss, mid);
  buildSegmentTree(right, (mid+1), se);

  segemntTree[si] = someOperation(segemntTree[left], segemntTree[right]);
}

int query(int si, int ss, int se, int qs, int qe) {
  // case 1 completely outside
  if((qs > se) || (qe < ss)) {  return INT_MAX; }
  // case 2 completely inside
  if((qs >= ss) && (qe <= se)) {
    return segemntTree[si];
  }

  int mid = ss + ((se - ss) >> 1);
  int left = si << 1;
  int right = left | 1;

  int ql = query(left, ss, mid, qs, qe);
  int qr = query(right, (mid+1), se, qs, qe);

  int minimus = someOperation(ql, qr);
  return minimus;
}



int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, q, qs, qe;
  cin>>n;
  for(int i=1; i<=n; i++) {
    cin>>a[i];
  }

  //cerr<<"debug 1\n";
  buildSegmentTree(1, 1, n);
  //cerr<<"debug 2\n";
  cin>>q;
  while(q--) {
    cin>>qs>>qe;
    // convert from 0 based to 1 based indexing
    qs+=1;
    qe+=1;

    cout<<query(1, 1, n, qs, qe)<<"\n";
  }

  return 0;
}