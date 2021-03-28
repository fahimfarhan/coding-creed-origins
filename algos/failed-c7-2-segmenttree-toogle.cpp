#include <bits/stdc++.h>
using namespace std;

#define MAXN 100
bool a[MAXN] = {0};
bool b[MAXN] = {0};

int tree[4*MAXN] = {0};
int lazy[4*MAXN] = {0};

inline int brQuery(int qs, int qe) {
  int ret = 0;
  for(int i=qs; i<=qe; i++) {
    ret += (int)b[i];
  }
  return ret;
}

inline void brUpdate(int us, int ue) {
  for(int i=us; i<=ue; i++) {
    b[i] = !b[i];
  }
}

inline void build(int si, int ss, int se) {
  if(ss == se) {
    tree[si] = (int)a[ss];
    return;
  }

  int mid = ss + ((se-ss)>>1);
  int left = si << 1;
  int right = left | 1;

  build(left, ss, mid);
  build(right, (mid+1), se);

  tree[si] = tree[left] + tree[right];
}

inline void lazyPropagate(int si, int ss, int se) {
  if(lazy[si]!=0) {
    if( (lazy[si]&1) == 1) {
      tree[si] = (se - ss + 1) - tree[si];
      if(ss != se) {
        int mid = ss + ((se-ss)>>1);
        int left = si << 1;
        int right = left | 1;

        lazy[left]+=lazy[si];
        lazy[right]+=lazy[si];
      }
    }
    lazy[si] = 0;
  }
}

inline int rangedQuery(int si, int ss, int se, int qs, int qe) {
  if((se < qs) || (qe < ss)) {
    return 0;
  }
  lazyPropagate(si, ss, se);
  if((qs <= ss) && (se <= qe)) {
    return tree[si];
  }

  int mid = ss + ((se-ss)>>1);
  int left = si << 1;
  int right = left | 1;

  int ql = rangedQuery(left, ss, mid, qs, qe);
  int qr = rangedQuery(right, (mid+1), se, qs, qe);

  return (ql + qr);
}

void printer() {
  cout<<"\n----- br ------\n";
  for(int i=1; i<=20; i++) {
    cout<<b[i]<<" ";  
  }
  cout<<"\n----- st ------\n";
  int power = 1;
  for(int i=1; i<=80; i++) {
    if(i == (1<<power)) {
      cout<<"\n";
      power++;
    }
    cout<<tree[i]<<" ";
  }
  cout<<"\n----------------------\n";
}

inline void rangedUpdate(int si, int ss, int se, int us, int ue) {
  if(se < us || ue < ss) {
    return;
  }
  lazyPropagate(si, ss, se);
  if((us <= ss) && (se <= ue)) {
    lazy[si]++;
    lazyPropagate(si, ss, se);
    return;
  }

  int mid = ss + ((se-ss)>>1);
  int left = si << 1;
  int right = left | 1;

  rangedUpdate(left, ss, mid, us, ue);
  rangedUpdate(right, (mid+1), se, us, ue);

  tree[si] = tree[left]+tree[right];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int N = 20;
  build(1, 1, N);

  int Q;
  int op, s, e;
  cin>>Q;
  while(Q--) {
    cin>>op>>s>>e;
    if(op == 1) {
      cout<<"-------- update -------------\n";
      rangedUpdate(1, 1, N, s, e);
      brUpdate(s, e);
      // printer();
    }else if(op ==2){
      cout<<"-------- query -------------\n";
      int x1 = rangedQuery(1, 1, N, s, e);
      int x2 = brQuery(s,e);
      cout<<"br-> "<<x2<<" st-> "<<x1<<"\n";
      // printer();
    }
  }

  return 0;
}