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

	int n;
    cin>>n;
    if(n==0 || n==1 || n==2){
        cout<<"No\n";
    }else{
        cout<<"Yes\n";
        int m=2;
        int stop = n/2;
        cout<<stop<<" ";
        for(int i=0; i<stop; i++){
            cout<<m<<" ";
            m+=2;
        }
        cout<<"\n";
        m = 1;
        cout<<n-stop<<" ";
        for(int i=0; i<n-stop; i++){
            cout<<m<<" ";
            m+=2;
        }
        cout<<"\n";
    }
	return 0;
}
