#include <bits/stdc++.h>
using namespace std;

#define MAX 1500000

int a[MAX];
int tree[4*MAX];
int lazy[4*MAX];

inline void build(int si, int ss, int se) {
  if(ss == se) {
    tree[si] = a[ss];
    return;
  }

  int left = si << 1;
  int right = left | 1;
  int mid = ss + ((se - ss)>>1);

  build(left, ss, mid);
  build(right, (mid+1), se);

  tree[si] = tree[left]+tree[right];
}

inline void lazyPropagation(int si, int ss, int se) {
  if(lazy[si]!=0) {
    if(lazy[si] == 1){   tree[si] = se - ss + 1; }
    else if(lazy[si] == 2) {  tree[si] = 0; }
    else if(lazy[si] == -1) { tree[si] = (se - ss + 1) - tree[si];  }


    if(ss != se) {
      int left = si << 1;
      int right = left | 1;
      if(lazy[si] == -1) {
        int mid = ss + ((se-ss)>>1);
        lazyPropagation(left, ss, mid);
        lazyPropagation(right, (mid+1), se);
      }
      lazy[left] = lazy[si];
      lazy[right] = lazy[si];
    }

    lazy[si] = 0;
  }
}

/*
-- ss1 -- se1 -- us -- ss -- se -- ue -- ss2 -- se2 --
*/
inline void updateRange(int si, int ss, int se, int us, int ue, int val) {
  lazyPropagation(si, ss, se);
  if(ss > se) { return; }
  if( (se < us) || (ue < ss) ) {  return; }

  if( (us <= ss) && (se <= ue) ) {
    lazy[si] = val;
    lazyPropagation(si, ss, se);
    return;
  }

  int mid = ss + ((se-ss)>>1);
  int left = si << 1;
  int right = left |1;

  updateRange(left, ss, mid, us, ue, val);
  updateRange(right, (mid+1), se, us, ue, val);

  tree[si] = tree[left]+tree[right];
}

/*
-- ss1 -- se1 -- qs -- ss -- se -- qe -- ss2 -- se2 --
*/

inline int query(int si, int ss, int se, int qs, int qe) {
  if(ss > se) { return 0; }
  if( (se < qs) || (qe < ss) ) {  return 0; }

  lazyPropagation(si, ss, se);
  
  if( (qs <= ss) && (se <= qe)) {
    return tree[si];
  }
  int mid = ss + ((se-ss)>>1);
  int left = si << 1;
  int right = left | 1;

  int qleft = query(left, ss, mid, qs, qe);
  int qright = query(right, (mid+1), se, qs, qe);

  return (qleft+qright);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int T;
  string s;
  cin>>T;

  for(int t=1; t<=T; t++) {
    int m,p;
    int COUNT = 0;
    cin>>m;

    for(int i = 1; i <= m; i++) {
      cin>>p;
      cin>>s;
      for(int j = 1; j <= p; j++) {
        for(int k = 0; k < s.size(); k++) {
          COUNT++;
          a[COUNT] = s[k] - '0';
        }
      }
    }

    memset(lazy, 0, sizeof(lazy));
    build(1, 1, COUNT);

    int q;
    cin>>q;
    int qCount = 0;
    char cmd;
    int a, b;

    cout<<"Case "<<t<<":\n";
    for(int i = 1; i <= q; i++) {
      cin>>cmd>>a>>b;
      a++; b++;
      if(cmd == 'F') {
        updateRange(1, 1, COUNT, a, b, 1);
      } else if(cmd == 'E') {
        updateRange(1, 1, COUNT, a, b, 2);
      } else if(cmd == 'I') {
        updateRange(1, 1, COUNT, a, b, -1);
      } else{
        qCount++;
        cout<<"Q"<<qCount<<": "<<query(1, 1, COUNT, a, b)<<"\n";
      }
    }
  }

  return 0;
}