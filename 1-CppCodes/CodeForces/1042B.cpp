#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);


map<string, int> mp;

int getSum(string a, string b){
    if(mp.count(a)==0 ||mp.count(b)==0 ){
        return INT_MAX;
    }else{
        return mp[a]+mp[b];
    }
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

	int n;
    int m; string s;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>m>>s;
        sort(s.begin(), s.end());
        if(mp.count(s)==0){
            mp[s] = m;
        }else{
            mp[s] = min(m,mp[s]);
        }
    }
    int ans = INT_MAX;
    if(mp.count("ABC")) ans = min(ans, mp["ABC"]);
    if(mp.count("A") && mp.count("B") && mp.count("C"))  ans = min(ans, mp["A"]+mp["B"]+mp["C"]);
    ans = min(ans, getSum("AB","C"));
    ans = min(ans, getSum("AC","B"));
    ans = min(ans, getSum("BC","A"));
    ans = min(ans, getSum("AB","AC"));
    ans = min(ans, getSum("AB","BC"));
    ans = min(ans, getSum("AC","BC"));
    
    if(ans == INT_MAX){ ans = -1; }
    cout<<ans<<"\n";
	return 0;
}
