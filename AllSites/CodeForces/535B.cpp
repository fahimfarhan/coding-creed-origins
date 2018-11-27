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

	int n, pos;
    string s;
    cin>>s;
    int l = s.length();
    // cout<<l<<"\n";
    n=0;
    pos = (1<<l)-1;
    for(int i=0; i<l; i++){
        n = n<<1;
        if(s[i]=='7'){
            n=n|1;
        }
    }

    pos+=n;
    cout<<pos<<"\n";
	return 0;
}
