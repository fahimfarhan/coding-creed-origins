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

    int a[30];
    for(int i=0; i<30; i++){   a[i] = 0; }
	int n;
    string s;
    cin>>n>>s;
    char which;
    bool b = true;
    for(int i=0; i<n; i++){
        int j = s[i] - 'a';
        a[j]++;
        if(a[j]>n/2){ which = s[i]; b = false; break; }
    }

    if(b){
        cout<<"YES\n";
        cout<<s.substr(0,n/2);
    }else{
        cout<<"NO\n";
    }


	return 0;
}
