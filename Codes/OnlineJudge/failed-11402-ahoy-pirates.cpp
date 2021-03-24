#include <bits/stdc++.h>

using namespace std;

bool *input;
int *tree;
int *lazy;

#define Buccaneer 1
#define Barbary 0

#define F 1  // -> convert to buccaneer
#define E 2  // -> convert to barbary
#define I 3  // inverse

inline void build(int si, int ss, int se) {
  // cerr<<"build -> "<<si<<" "<<ss<<" "<<se<<"\n";
  if(ss == se) {
    tree[si] = (int)input[ss];
    return;
  }

  int mid = ss + ((se - ss)>>1); // must use this bracket! else you get segmentation fault!!!
  int left = si << 1;
  int right = left | 1;

  build(left, ss, mid);
  build(right, (mid+1), se);

  tree[si] = tree[left]+tree[right];
}

/*  --- ss1 --- se1 -- qs -- ss -- se -- qe -- ss2 -- se2 -- */
inline int query(int si, int ss, int se, int qs, int qe) {
  int left = si << 1;
  int right = left | 1;
  
  if(lazy[si]!=0) {
    int dx = lazy[si];
    lazy[si] = 0;

    if(dx == F) {
      tree[si] = (se - ss + 1);
    }else if(dx == E) {
      tree[si] = 0;
    }else if(dx == I) {
      int temp = tree[si];
      tree[si] = (se - ss + 1) - temp;
    }
    
    if(ss!=se) {
      tree[left] = dx;
      tree[right] = dx;
    } 
  }

  if( (se < qs) || (qe < ss)) {
    return 0;
  }

  if( (qs <= ss) && (se <= qe)) {
    return tree[si];
  }

  int mid = ss + ((se - ss)>>1);
  int qleft = query(left, ss, mid, qs, qe);
  int qright = query(right, (mid+1), se, qs, qe);

  return (qleft + qright);
}

/*
--- ss1 --- se1 --- us --- ss --- se --- ue --- ss2 --- se2 ---
*/
inline void update(int si, int ss, int se, int us, int ue, int value) {
  int left = si << 1;
  int right = left | 1;

  if(lazy[si]!=0) {
    int dx = lazy[si];
    lazy[si] = 0;

    if(dx == F) {
      tree[si] = (se - ss + 1);
    }else if(dx == E) {
      tree[si] = 0;
    }else if(dx == I) {
      int temp = tree[si];
      tree[si] = (se - ss + 1) - temp;
    }
    
    if(ss!=se) {
      tree[left] = dx;
      tree[right] = dx;
    } 
  }

  if( (se < us) || (ue < ss)) {
    return;
  }

  if( (us <= ss) && (se <= ue) ) {
    lazy[si] = value;
    return;
  }

  int mid = ss + ((se-ss)>>1);
  update(left, ss,mid, us, ue, value);
  update(right, (mid+1), se, us, ue, value);
  tree[si] = tree[left]+tree[right];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int T1;
  cin>>T1;
  for(int t=1; t<=T1; t++) {
    cout<<"Case "<<t<<":\n";
    int M, T;
    string s = "", pirates = "";
  
    cin>>M;
    while(M--) {
      cin>>T;
      cin>>s;

      for(int i=0; i<T; i++) {
        pirates = pirates + s;
      }
    }

    // so pirates = input
    // cerr<<pirates<<"\n";

    int N = pirates.size();
    int maxn = ((N+1) << 2);
    
    input = new bool[N+1];
    tree = new int[maxn];
    lazy = new int[maxn];

    pirates = "x"+pirates; // to make it 1 based indexing...
    for(int i=1; i<=N; i++) {
      input[i] = pirates[i] - '0';
    }

    build(1, 1, N);

    // for(int i=1; i<maxn; i++) {
    //   cout<<tree[i]<<" ";
    // }cout<<"\n";

    for(int i=0; i<maxn; i++) {  lazy[i] = 0;  }

    build(1, 1, N);

    int Q;
    cin>>Q;
    char ch;
    int a, b;

    int queryNo = 0;

    while(Q--) {
      cin>>ch>>a>>b;
      // cerr<<ch<<" "<<a<<" "<<b<<"\n";
      if(ch == 'S' ) {
        queryNo++;
        cout<<"Q"<<queryNo<<": "<<query(1, 1, N, (a+1), (b+1) )<<"\n";
      }else{
        int lazyUpdate = 0;
        if(ch == 'F') {
          lazyUpdate = F;
        }else if(ch == 'E') {
          lazyUpdate = E;
        }else if(ch == 'I') {
          lazyUpdate = I;
        }
        update(1, 1, N, (a+1), (b+1), lazyUpdate);
      }
    }

    delete[] lazy;
    delete[] tree;
    delete[] input;
  }

  return 0;
}