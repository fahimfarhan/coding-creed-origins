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

	int n; //, count;
    string s, ans;
    // count = 0;
    ans = "";
    cin>>s;
    sort(s.begin(), s.end());

    char ch = s[s.size()-1];
    for(int i=s.size()-1; i>=0; i--){
      if(ch==s[i]){  ans+=ch; }
      else{ break; }
    }

    cout<<ans<<"\n";
	return 0;
}
