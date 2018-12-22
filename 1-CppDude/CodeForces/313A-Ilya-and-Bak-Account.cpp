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

	int n, ans;
	cin>>n;
	ans = 0;
	if(n<0)
	{
		n=-n;
		int m = n/100;
		int f = n%10;
		int s = (n/10)%10;

		if(f>s){	ans+=s; }
		else{	ans+=f; }
		ans+=m*10;
		ans = -ans;
		
	}
	else{
		ans = n;
	}
	cout<<ans<<"\n";

	return 0;
}

