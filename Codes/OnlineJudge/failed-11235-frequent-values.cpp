#include <bits/stdc++.h>
using namespace std;

#define ll int

#define VALUE first
#define COUNT second

ll *a;
pair<ll,ll> *st;
map<ll,ll> mpFirst, mpLast;

inline void buildSegmentTree(int si, int ss, int se) {
  if(ss == se) {
    st[si] = {a[ss], 1};
    return;
  }

  int mid = ss + ((se - ss)>>1);
  int left = si << 1;
  int right = left | 1;

  buildSegmentTree(left, ss, mid);
  buildSegmentTree(right, (mid+1), se);

  if(st[left].VALUE == st[right].VALUE) {
    st[si] = {st[left].VALUE, st[left].COUNT+st[right].COUNT};
  }else{
    // todo: use map
    // take max for lower limit,
    // min for upper limit

    int val1 = st[left].VALUE;
    int start1 = max(ss, mpFirst[val1]);
    int end1 = min(se, mpLast[val1]);
    int count1 = end1 - start1 + 1;

    int val2 = st[right].VALUE;
    int start2 = max(ss, mpFirst[val2]);
    int end2 = min(se, mpLast[val2]);
    int count2 = end2 - start2 + 1;

    if(count1 > count2) {
      st[si] = {val1, count1};
    }else{
      st[si] = {val2, count2};
    }
  }
}

/*
--- ss1 --- se1 --- qs --- ss --- se --- qe --- ss2 --- se2 ---
*/
inline pair<int, int> query(int si, int ss, int se, int qs, int qe) {
  if( (se < qs) || (qe < ss)) {  return {INT_MIN, 0}; }  // case1 : completely outside
  if((qs <= ss) && (se <= qe) ) { // case 2: completely inside
    return st[si];
  }

  int mid = ss + ((se - ss)>>1);
  int left = si << 1;
  int right = left | 1;

  pair<int, int> qLeft = query(left, ss, mid, qs, qe);
  pair<int, int> qRight = query(right, (mid+1), se, qs, qe);

  if(qLeft.VALUE == qRight.VALUE) {
    return {  qLeft.VALUE, (qLeft.COUNT + qRight.COUNT) };
  }else{
    int val1 = qLeft.VALUE;
    int start1 = max(ss, mpFirst[val1]);
    int end1 = min(se, mpLast[val1]);
    int count1 = end1 - start1 + 1;

    int val2 = qRight.VALUE;
    int start2 = max(ss, mpFirst[val2]);
    int end2 = min(se, mpLast[val2]);
    int count2 = end2 - start2 + 1;

    if(count1 > count2) {
      return {val1, count1};
    }else{
      return {val2, count2};
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, Q;

  cin>>N>>Q;

  a = new ll[N+1];
  st = new pair<ll,ll>[4*(N+1)];

  for(int i=1; i<=N; i++) {  cin>>a[i];  }
  for(int i=1; i<=N; i++) {
    if(!mpFirst[a[i]]) {  mpFirst[a[i]] = i;  }
    mpLast[a[i]] = i;
  }

  buildSegmentTree(1,1,N);

  int i, j;
  while (Q--){
    /* code */
    cin>>i>>j;
    cout<<query(1,1,N,i,j).COUNT<<"\n";
  }
  cin>>i;
   
  delete[] st;
  delete[] a;
  return 0;
}