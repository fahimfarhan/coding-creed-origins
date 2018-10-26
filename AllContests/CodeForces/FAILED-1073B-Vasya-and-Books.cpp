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
    map<int, int> mp;
    cin>>n;
    for(int i=1; i<=n; i++){
        int m;
        cin>>m;
        mp[m] = i;
    }

    //int a[n+1];
    int ans = 0; int count = 0;
    for(int i=1; i<=n; i++){
        //cin>>a[i];
        int a;
        cin>>a;
        for(int j=1; j<=mp[a]; j++){
            if(mp[j]){   count++; mp[j] = 0; }
        }
        //ans+=count;
        cout<<count<<" ";
        count=0;
    }

    cout<<"\n";
	return 0;
}
