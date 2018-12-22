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
	ll  m,a,b, sum, count;
    ll *d;
    sum = 0;
    count=0;
    cin>>n>>m;
    d = new ll[n];
    for(int i=0; i<n; i++){
        cin>>a>>b;
        sum+=a;
        d[i] = b-a;
    }
    sort(d,d+n);

    for(int i=0; i<n; i++){
        if(sum>m){  sum = sum+d[i]; count++; }
        else{   break; }
    }
    if(sum>m){  cout<<"-1\n"; }
    else{       cout<<count<<"\n"; }
	return 0;
}
