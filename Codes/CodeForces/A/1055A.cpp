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

    int n,s;
    int *f,*b;
    cin>>n>>s;
    f = new int[n+1];
    b = new int[n+1];
    
    for(int i=1; i<=n; i++){  cin>>f[i];  }
    for(int i=1; i<=n; i++){  cin>>b[i];  }

    if(f[1]==0){  cout<<"NO\n"; }
    else if(f[s] == 1){ cout<<"YES\n";  }
    else if( b[s] == 0) {  cout<<"NO\n"; }
    else{
      bool b1 = false;
      for(int i=s; i<=n; i++){
        if( (f[i]&b[i]) == 1){
          cout<<"YES\n";
          b1 = true;
          break;
        }
      }
      if(!b1){   cout<<"NO\n";  }
    }

	  return 0;
}
