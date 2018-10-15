#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);

int main(int argc, char const *argv[])
{
	/* code */
  /* Soln soln */
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

	ll n,m, min, max, *kn;
    
    cin>>n>>m;
    kn = new ll[n+5];
    kn[0]=0; kn[1]=0; kn[2]=1;
    for(int i=2; i<=n; i++){
        kn[i+1] = kn[i]+i;
    }

    int lb = lower_bound(kn, kn+n+1, m)-kn;
    int used = lb;
   
    if(m==0){
        max = n; min = n;
    }
   else{
        max = n-used;
        min = n-m*2;
        if(min<0){  min = 0; }
    }
    cout<<min<<" "<<max<<"\n";
    if(!kn)delete[] kn;
	return 0;
}
