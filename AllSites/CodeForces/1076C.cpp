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

	int d,T;
    cin>>T;
    while(T--){
        bool b = true;
        cin>>d;
        if(d<4 && d!=0){    cout<<"N\n"; }
        else{
            double a1 = 0.5*(d+sqrt(d*d - 4*d));
            double a2 = 0.5*(d-sqrt(d*d - 4*d));

            cout << fixed << showpoint;
            cout << setprecision(9);
            cout<<"Y "<<a1<<" "<<a2<<"\n";
        }
    }
	return 0;
}
