#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);

	int n,m,lcm1,gcd1, *g,*b;
    vector<int> *G;

int main(int argc, char const *argv[])
{
	/* code */
  /* Soln soln */
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
    cin>>n>>m;
    gcd1 = __gcd(m,n);
    lcm1 = m*n/gcd1;
    b = new int[n];
    g = new int[m];
    for(int i=0; i<n; i++){ b[i] = 0; }
    for(int i=0; i<m; i++){ g[i] = 0; }
    
    G = new vector<int>[n+m];

    int h,x;
    cin>>h;
    while(h--){
        cin>>x;
        b[x] = 1;
    }

    cin>>h;
    while(h--){
        cin>>x;
        g[x] = 1;
    }

    int minimus = min(n,m);
    int maximus = max(n,m);

    for(int u=0; u<minimus; u++){
        int j = maximus;
        int v = u;
        while(j--){
            G[u].push_back(v+minimus);
            G[v+minimus].push_back(u);
            v+=gcd1%maximus;
        }
    }

    
    for(int i=0; i<m+n; i++){
        for(int j=0; j<G[i].size(); j++){
            cout<<G[i][j]<<"-->";
        }cout<<"\n";
    }
    


    if(!b)delete[] b;
    if(!g)delete[] g;
    if(!G)delete[] G;

	return 0;
}
