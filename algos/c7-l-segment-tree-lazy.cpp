#include <bits/stdc++.h>
using namespace std;

#define MAXN 20+5

class SegmentTree {
public:
  int a[MAXN] = {0};
  int tree[4*MAXN] = {0};
  int lazy[4*MAXN] = {0};

  SegmentTree(vector<int> v, int n) {
    for(int i=1; i<=n; i++) {
      a[i] = v[i];
    }
  }
  void build(int si, int ss, int se) {
    if(ss == se) {
      tree[si] = a[ss];
      return;
    }

    int mid = ss + ((se-ss)>>1);
    int left = si << 1;
    int right = left | 1;

    build(left, ss, mid);
    build(right, (mid+1), se);

    tree[si] = tree[left]+tree[right];
  } 

  void printer() {
    int power = 1;
    for(int i=1; i<=80; i++) {
      if(1<<power == i) {
        cout<<"\n";
        power++;
      }
      cout<<tree[i]<<" ";
    }
    cout<<"\n-------------------------------\n";
  }

  void lazyPropagation(int si, int ss, int se) {
    if(lazy[si]!=0) {
      tree[si] = tree[si] + (lazy[si] * (se - ss + 1));
      if(ss != se) {
        int left = si << 1;
        int right = left | 1;

        lazy[left] += lazy[si];
        lazy[right] += lazy[si];
      }
      lazy[si] = 0;
    }
  }

  /*
  --- ss1 --- se1 --- qs --- ss --- se --- qe --- ss2 --- se2 ---
  */
  int rangedQuery(int si, int ss, int se, int qs, int qe) {
    if( (se < qs) || (qe < ss)) {
      return 0;
    }
    lazyPropagation(si, ss, se);
    if((qs <= ss) && (se <= qe)) {
      return tree[si];
    }

    int mid = ss + ((se-ss)>>1);
    int left = si << 1;
    int right = left | 1;

    int ql = rangedQuery(left, ss, mid, qs, qe);
    int qr = rangedQuery(right, (mid+1), se, qs, qe);

    return (ql+qr);
  }

  /*
  --- ss1 --- se1 --- us --- ss --- se --- ue --- ss2 --- se2 ---
  */
  void rangedUpdate(int si, int ss, int se, int us, int ue, int val) {
    if(se < us || ue < ss) {
      return;
    }
    lazyPropagation(si, ss, se);

    if((us <= ss) && (se <= ue)) {
      lazy[si] = val;
      lazyPropagation(si, ss, se);
      return;
    }

    int mid = ss + ((se-ss)>>1);
    int left = si << 1;
    int right = left | 1;

    rangedUpdate(left, ss, mid, us, ue, val);
    rangedUpdate(right, (mid+1), se, us, ue, val);

    tree[si] = tree[left]+tree[right];
  }
};

class BruteForce{
public:
int a[MAXN] = {0};
  BruteForce() {}
  void build(vector<int> v, int n) {
    for(int i=1; i<=n; i++) {
      a[i] = v[i];
    }
  }

  int rangedQuery(int qs, int qe) {
    int ret = 0;
    for(int i=qs; i<=qe; i++) {
      ret+=a[i];
    }
    return ret;
  }

  void rangedUpdate(int us, int ue, int v) {
    for(int i=us; i<=ue; i++) {
      a[i]+=v;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  vector<int> v(MAXN);
  v[0] = 0;
  int N, m;
  cin>>N;
  for(int i=1; i<=N; i++) {
    cin>>v[i];
  }

  BruteForce bruteForce;
  SegmentTree st(v, N);
  st.build(1,1, N);
  st.printer();
  bruteForce.build(v, N);

  cout<<"bruteForce.rangedQuery(1, 10) = "<<bruteForce.rangedQuery(1, 10)<<"\n";
  cout<<"bruteForce.rangedQuery(11,20) = "<<bruteForce.rangedQuery(11, 20)<<"\n";

  int Q;
  int op, ss1, se1, val;
  cin>>Q;
  cerr<<"Q = "<<Q<<"\n";
  while(Q--) {
    cin>>op;
    if(op == 1) {
      cin>>ss1>>se1;
      cerr<<op<<" "<<ss1<<" "<<se1<<"\n";
      int x1 = bruteForce.rangedQuery(ss1, se1);
      int x2 = st.rangedQuery(1, 1, N, ss1, se1);
      cout<<"bf-q = "<<x1<<" st-q = "<<x2<<"\n";
    }else if(op == 2) {
      cin>>ss1>>se1>>val;
      cerr<<op<<" "<<ss1<<" "<<se1<<" "<<val<<"\n";
      bruteForce.rangedUpdate(ss1, se1, val);
      st.rangedUpdate(1, 1, N, ss1, se1, val);
    }
  }

  return 0;
}