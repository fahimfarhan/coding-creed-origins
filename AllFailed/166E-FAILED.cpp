#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);

#define A 0
#define B 1
#define C 2
#define D 3
int n;
ll **a;


int calculate(int depth, int pos){
    int ret = 0;
    if(a[depth][pos] >= 0 ){ 
        return a[depth][pos]; 
    }
    
    for(int i=0; i<4; i++){
        if(i!=pos){ 
            ret=ret+ calculate(depth-1, i);  
            ret = ret%1000000007;
        }
    }
    ret = ret%1000000007;
    a[depth][pos]=ret;
    return ret;
}

int main(int argc, char const *argv[])
{
	/* code */
  /* Soln soln */
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

	//int n;
    cin>>n;
    a = new ll*[n+1];
    for(int i=0; i<=n; i++){
        a[i] = new ll[4];
    }

    for(int i=0; i<=n; i++){
        for(int j=0; j<4; j++){
            a[i][j] = -1;
        }
    }
    // base case!
    a[0][D] = 1;
    a[0][A] = 0; a[0][B] = 0; a[0][C] = 0;
    // recursion!
    ll ans = calculate(n,D);
    cout<<ans<<"\n";

    for(int i=0; i<=n; i++){
        for(int j=0; j<4; j++){
            cout<<a[i][j]<<" ";
        }cout<<"\n";
    }

    for(int i=0; i<=n; i++){    if(!a[i]) delete[] a[i]; }
    if(!a)delete[] a;
	return 0;
}
