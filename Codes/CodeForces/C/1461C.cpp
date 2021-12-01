#include <bits/stdc++.h>
using namespace std;

int t, n, m, r;
int maximus;
double p, prob, nProb;

int *a;


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin>>t;
  while(t--) {
    cin>>n>>m;
    a = new int[n+1];
    for(int i = 1; i <= n; i++) {  cin>>a[i];  }
    maximus = -1;
    for(int i=1; i<=n; i++) {
      if(i != a[i]) { maximus = i;  }
    }

    
    nProb = 1;
    for(int i = 0; i < m; i++) {
      cin>>r>>p;
      if(r < maximus) {
        p = 0;
      } 
      nProb = nProb * (1 - p);
    }

    if(maximus == -1) {
      cout<<1<<"\n";
      continue;
    }

    prob = 1 - nProb;

    // cout<<prob<<"\n";
  	// cout << setprecision(8);
  	cout << fixed << setprecision(8) << prob << endl;

    
    delete[] a;
  }

  return 0;
}