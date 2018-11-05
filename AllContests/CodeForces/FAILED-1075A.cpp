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

	int64_t n,a,b;
    double d1,d2;
    cin>>n>>a>>b;
    d1 = sqrt( (a-1)*(a-1)+(b-1)*(b-1)  );
    d2 = sqrt( (n-a)*(n-a)+(n-b)*(n-b)  );
    if(d1<=d2){
        cout<<"White\n";
    }else{
        cout<<"Black\n";
    }
	return 0;
}
