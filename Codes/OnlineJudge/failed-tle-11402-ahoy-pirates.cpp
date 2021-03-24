#include <bits/stdc++.h>

using namespace std;

bool *input;
int *tree;
// int *lazy;
vector<int> lazy;

#define Buccaneer 1
#define Barbary 0

#define F 1  // -> convert to buccaneer
#define E 2  // -> convert to barbary
#define I 3  // inverse
int mp[100] = {0};

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

inline void lazyPropagation(int si, int ss, int se) {
  if(lazy[si]!=0) {
    if(lazy[si] == F) {
      tree[si] = (se - ss + 1);
    }else if(lazy[si] == E) {
      tree[si] = 0;
    }else if(lazy[si] == I) {
      tree[si] = (se - ss + 1) - tree[si];
    }

    if(ss != se) {
      // Anik only inverse er jonno lazy propagate korse. keno? o.O
      // always recursive call korle etato r lazy holo na... I guess that's why
      int left = si << 1;
      int right = left | 1;
      
      if(lazy[si] == I) {
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

/*  --- ss1 --- se1 -- qs -- ss -- se -- qe -- ss2 -- se2 -- */
inline int query(int si, int ss, int se, int qs, int qe) {
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
  int qleft = query(left, ss, mid, qs, qe);
  int qright = query(right, (mid+1), se, qs, qe);

  return (qleft+qright);
}

/*
--- ss1 --- se1 --- us --- ss --- se --- ue --- ss2 --- se2 ---
*/
inline void update(int si, int ss, int se, int us, int ue, int value) {
  lazyPropagation(si, ss, se);
  if((se < us) || (ue < ss)) {  return; }
  if((us <= ss) && (se <= ue)) {
    lazy[si] = value;
    lazyPropagation(si, ss, se);
    return;
  }

  int mid = ss + ((se-ss)>>1);
  int left = si << 1;
  int right = left | 1;

  update(left, ss, mid, us, ue, value);
  update(right, (mid+1), se, us, ue, value);

  tree[si] = tree[left] + tree[right];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  mp[(int)'F'] = F;
  mp[(int)'E'] = E;
  mp[(int)'I'] = I;

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
    
    input = new bool[N+1];  tree = new int[maxn]; // lazy = new int[maxn];
    lazy.resize(maxn, 0);

    pirates = "x"+pirates; // to make it 1 based indexing...
    for(int i=1; i<=N; i++) {  input[i] = pirates[i] - '0';  }

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
      if(ch == 'S') {
        queryNo++;
        cout<<"Q"<<queryNo<<": "<<query(1, 1, N, (a+1), (b+1))<<"\n";
      }else{
        int value = mp[(int)ch];
        update(1, 1, N, (a+1), (b+1), value);
      }
    }
  
    delete[] tree;  delete[] input;
  }

  return 0;
}