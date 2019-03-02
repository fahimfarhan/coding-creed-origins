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
    int A[10] = {0,1,2,3,4,5,6,7,8,9};
    string s;
    cin>>s;
    for(int i=0; i<s.size(); i++){
        int x = s[i]-'0';
        x=(x+1)%10;
        cout<<x;
    }
    cout<<"\n";

	return 0;
}
