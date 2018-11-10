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

	int n,m,k,y, count, ans;
    int *a;

  count = 0;
  ans = 0;
  cin>>n>>m>>k;
    a = new int[m+1];
  for(int i=0; i<=m; i++){
      cin>>a[i];
  }  

  for(int i=0; i<m; i++){
      
      y=a[i]^a[m];
      
      while(y>0){
        
        if( (y&1)==0 ){   count++;   } 
        y = y>>1;
      }

      if(count<=k){ ans++; }
  }
  cout<<ans<<"\n";
  if(!a)delete[] a;
	return 0;
}
