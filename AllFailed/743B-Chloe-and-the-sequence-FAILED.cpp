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

	int n,k,sz, mid_pos, ans;
    ans = n;
    sz = 01;
    cin>>n>>k;
    for(int i=01; i<n; i++){
        sz = 1+sz<<1;
    }

    mid_pos = 1+sz>>1;
    while(true){
        if(mid_pos==k){ break;  }
        else{   
            sz = sz>>1;
                mid_pos = 1+sz;
                ans--;
        }
    }
    
    cout<<ans<<"\n";
	return 0;
}
