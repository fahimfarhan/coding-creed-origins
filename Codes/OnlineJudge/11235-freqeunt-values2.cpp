#include <bits/stdc++.h>
using namespace std;

int *input, *freq, *start, *tree;
map<int, int> mp;

inline void build(int si, int ss, int se) {
  if(ss == se) {
    tree[si] = freq[ss];
    return;
  }

  int mid = ss + ((se-ss)>>1);
  // int left = se << 1;
  int left = si << 1;
  int right = left | 1;

  build(left, ss, mid);
  build(right, (mid+1), se);

  tree[si] = max(tree[left], tree[right]);
}


/*
--- ss1 --- se1 --- qs --- ss --- se --- qe --- ss2 --- se2 ---
*/
inline int query2(int si, int ss, int se, int qs, int qe) {
  if( (se < qs) || (qe < ss) ) {  return INT_MIN; }
  if( (qs <= ss) && (se <= qe) ) { return tree[si];  }

  int mid = ss + ((se - ss) >> 1);
  int left = si << 1;
  int right = left | 1;

  int qleft = query2(left, ss, mid, qs, qe);
  int qright = query2(right, (mid+1), se, qs, qe);
  int maximus = max(qleft, qright);
  return maximus;
}

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
  int N, Q;
  while(true) {
    cin>>N;
    if(N == 0) {  break;  }
    cin>>Q;

    int m = N+1;
    input = new int[m];
    freq = new int[m];
    start = new int[m];
    tree = new int[(m<<2)];

    /** Preprocess */
    for(int i=0; i<=N; i++) { input[i] = 0; start[i] = 0; freq[i] = 0;  }
    for(int i=0; i<m; i++) { tree[i] = 0;  }

    for(int i=1; i<=N; i++) {
      cin>>input[i];
      mp[input[i]]++;
    }

    int pos = -1, value = INT_MIN;    
    for(int i=1; i<=N; i++) {
      freq[i] = mp[input[i]];
      if(value != input[i]) {
        pos = i;
        value = input[i];
      }
      start[i] = pos;
    }

    // init segment tree
    build(1, 1, N);

    printer(N);

    while(Q--) {

      int qs, qe;
      cin>>qs>>qe;

      if(input[qs] == input[qe]) {
        cout<<(qe - qs + 1)<<"\n";
      }else{

        int posAfterFirstNumEnd = start[qs] + freq[qs];
        int kount1 = posAfterFirstNumEnd - qs;
        int kount2 = qe - start[qe] + 1;
        int kount3 = query(1, 1, N, (posAfterFirstNumEnd), (start[qe] - 1) ); 

        cerr<<"debug "<<kount1<<" "<<kount2<<" "<<kount3<<"\n";

        int maximus = max(kount1, max(kount2, kount3));

        cout<<maximus<<"\n";
      }
    }


    delete[] input;
    delete[] freq;
    delete[] start;
    delete[] tree;
    mp.clear();
  }
  return 0;
}