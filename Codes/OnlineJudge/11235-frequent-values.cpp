/**
 * special thanks to:
 * https://arunima1590.wordpress.com/2017/03/28/uva-11235-frequent-values/
 * 
*/

#include <bits/stdc++.h>
using namespace std;

#define MX 100005

// #define mid(ss,se) ss+((se-ss)>>1)
// #define lt(si) si<<1
// #define rt(left) left|1

int *input, *freq, *start, *tree;

map<int, int> mp;

inline void build(int si, int ss, int se) {
  if(ss == se) {
    tree[si] = freq[ss];
    return;
  }

  int left = si<<1;
  int right = left|1;

  int mid = ss+((se-ss)>>1);
  build(left, ss, mid);
  build(right,(mid+1), se);

  // tree[si] = tree[left]+tree[right]; // this is the real culprit!!!!!
  tree[si] = max(tree[left], tree[right]);
}

/*
--- ss1 --- se1 --- qs --- ss --- se --- qe --- ss2 --- se2 ---
*/
inline int query(int si, int ss, int se, int qs, int qe) {
  if((se < qs) || (qe < ss)) {  return INT_MIN; }
  if((qs <= ss) && (se <= qe)) { return tree[si];  }

  int mid = ss+((se-ss)>>1);
  int left = si<<1;
  int right = left|1;

  int qleft = query(left, ss, mid, qs, qe);
  int qright = query(right, (mid+1), se, qs, qe);
  int maximus = max(qleft, qright);
  return maximus;
}

void printer(int n) {
  cout<<"----- input --------\n";
  for(int i=1; i<=n; i++) {
    cout<<input[i]<<" ";
  }cout<<"\n";

  
  cout<<"----- start --------\n";
  for(int i=1; i<=n; i++) {
    cout<<start[i]<<" ";
  }cout<<"\n";

  cout<<"----- freq --------\n";
  for(int i=1; i<=n; i++) {
    cout<<freq[i]<<" ";
  }cout<<"\n";

cout<<"----- tree --------\n";
  for(int i=0; i<=4*n; i++) {
    cout<<tree[i]<<" ";
  }cout<<"\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int N, Q;

  while (true){
    /* code */
    cin>>N;
    if(N == 0) {  break;  }

    input = new int[N+1];
    freq = new int[N+1];
    start = new int[N+1];
    tree = new int[4*(N+1)];

    for(int i=0; i<=N; i++) {
      input[i] = 0; freq[i] = 0; start[i] = 0;
    }

    int m = 4*N;
    for(int i=0; i<=m; i++) {
      tree[i] = 0;
    }
    
    cin>>Q;

    for(int i=1; i<=N; i++) {
      cin>>input[i];
      mp[input[i]]++;
    }

    int pos, val = INT_MIN;
    for(int i=1; i<=N; i++) {
      freq[i] = mp[input[i]];

      if(input[i] != val) {
        val = input[i];
        pos = i; 
      }
      start[i] = pos;
    }

    build(1,1,N);

    // printer(N);

    while(Q--) {
      int qs, qe;
      cin>>qs>>qe;

      if(input[qs] == input[qe]) {
        cout<<(qe - qs + 1)<<"\n";
      }else{
        int ks = start[qs] + freq[qs];
        int kount1 = ks - qs; // + 1;
        int kount2 = qe - start[qe] + 1;
        int kount3 = query(1, 1, N, ks, (start[qe] - 1) );

        // cerr<<"debug "<<kount1<<" "<<kount2<<" "<<kount3<<"\n";
        int result = max(kount1, max(kount2, kount3));

        cout<<result<<"\n";
      }
    }
    mp.clear();
    // *input, *freq, *start, *tree
    delete[] input;
    delete[] freq;
    delete[] start;
    delete[] tree;
  }
  

  return 0;
}