#include <bits/stdc++.h>
using namespace std;

const int maxn = 20+10;
int a[maxn] = {0};
int b[maxn] = {0};
int tree[4*maxn] = {0};
int lazy[4*maxn] = {0};

inline int toogle(int a) {
  if(a == 0) {  return 1; }
  return 0;
}

inline void brUpdate(int us, int ue) {
  for(int i=us; i<=ue; i++) {
    b[i] = toogle(b[i]);
  }
}

inline int brQuery(int qs, int qe) {
  int ret = 0;
  for(int i=qs; i<=qe; i++) {
    ret += b[i];
  }

  return ret;
}

inline void printer() {
  for(int i=1; i<=20; i++) {
    cout<<b[i]<<" ";
  }cout<<"\n";
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int Q, op, l, r;
  cin>>Q;
  while(Q--) {
    cin>>op>>l>>r;
    if(op == 1) {
      brUpdate(l, r);
      printer();
    }else{
      cout<<brQuery(l, r)<<"\n";
      printer();
    }
  }


  return 0;
}