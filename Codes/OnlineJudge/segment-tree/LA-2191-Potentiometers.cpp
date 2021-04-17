#include <bits/stdc++.h>

using namespace std;

int *input;
int *tree;
int N;

inline void build(int si, int ss, int se) {
  if(ss == se) {
    tree[si] = input[ss];
    return;
  }

  int mid = ss + ((se-ss)>>1);
  int left = si << 1;
  int right = left | 1;

  build(left, ss, mid);
  build(right, (mid+1), se);
}

/*
-- ss1 -- se1 -- qs --ss -- se -- qe -- ss2 -- se2 --
*/
inline int rangedQuery(int si, int ss, int se, int qs, int qe) {
  if( (ss > se) || (qs > qe)) {  return 0;  }
  if( (se < qs) || (qe < ss) ) {
    return 0;
  }
  if( (qs <= ss) && (se <= qe) ) {
    return tree[si];
  }

  int mid = ss + ((se-ss)>>1);
  int left = si << 1;
  int right = left | 1;

  int qleft = rangedQuery(left, ss, mid, qs, qe);
  int qright = rangedQuery(right, (mid+1), se, qs, qe);

  return (qleft + qright);
}

inline void pointUpdate(int si, int ss, int se, int u, int v) {
  if(ss > se) { return; }
  if( (u < ss) || (se < u) ) {  return; }

  if(ss == se) {
    tree[si] = v;
    input[ss] = v;
    return;
  }

  int mid = ss + ((se - ss)>>1);
  int left = si << 1;
  int right = left | 1;

  if( (ss <= u) && (u <= mid) ) {
    pointUpdate(left, ss, mid, u, v);
  }else if( ((mid+1) <= u) && (u <= se)) {
    pointUpdate(right, (mid+1), se, u, v);
  }
  // else{
  //   return;
  // }
  tree[si] = tree[left] + tree[right];
}

inline void start() {
  input = new int[N+1];
  tree = new int[ ((N+1) << 2) ];

  for(int i=1; i<=N; i++) { cin>>input[i];  }

  // init tree
  build(1, 1, N);

  string s;
  while(getline(cin, s)) {
    if(s == "END") {  break;  }
    else{
      char cmd;
      int x, y;

      stringstream ss(s);
      ss>>cmd>>x>>y;
      if(cmd == 'S') {
        // todo: pointUpdate
        pointUpdate(1, 1, N, x, y);
      }else if(cmd == 'M') {
        // todo: query
        int resistance = rangedQuery(1, 1, N, x, y);
        cout<<resistance<<"\n";
      }
    }
  }

  delete[] tree;
  delete[] input;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);


  int t = 1;
  while(true) {
    cin>>N;
    if(N == 0) {  break;  }
    else{
      cout<<"Case "<<t<<":\n";
      start();
      cout<<"\n";
      t++;
    }
  }


  return 0;
}