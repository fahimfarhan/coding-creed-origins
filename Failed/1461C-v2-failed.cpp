#include <bits/stdc++.h>
using namespace std;

int t;
int n,m, maximus;

int *a, *r;
double *p;

inline double probablilityRec(const int& i, const int& M) {
  if(i == M) {
    return p[i];
  }
  double prob = p[i] * probablilityRec((i+1), M) + (1 - p[i]) * probablilityRec((i+1), M);
  return prob;
}

int main(int argc, char const *argv[])
{
	/* code */
  /* Soln soln */
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  /*
  cout << setprecision(8);
  cout << num1 << endl;
  */
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin>>t;
  while(t--) {
    cin>>n>>m;
    a = new int[n+1];
    r = new int[m+1];
    p = new double[m+1];

    for(int i=1; i<=n; i++) {
      cin>>a[i];
    }

    for(int i=1; i<=m; i++) {
      cin>>r[i]>>p[i];
    }

    maximus = -1;
    for(int i=1; i<=n; i++) {
      if(a[i] != i) {
        maximus = i;
      }
    }

    for(int i=1; i<=m; i++) {
      if(r[i] < maximus) {
        p[i] = 0;
      }
    }

    double prob = 1;
    if(maximus != -1) {
      prob = probablilityRec(1, m);
    }

  	cout << fixed << setprecision(8) << prob << endl;

    delete[] r;
    delete[] p;
    delete[] a;
  }

  return 0;
}
