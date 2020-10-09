#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);

class Soln{
private:
    int n;
public:
    Soln(){}
    ~Soln(){}
};

int main(int argc, char const *argv[])
{
	/* code */
  /* Soln soln */
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

	int a[3], b[3];
    for(int i=0; i<3; i++){ cin>>a[i];}
    for(int i=0; i<3; i++){ cin>>b[i];}
    
    int pointsAlice = ((a[0]>b[0])?1:0)+ ((a[1]>b[1])?1:0)+ ((a[2]>b[2])?1:0) ;
    int pointsBob = ((a[0]<b[0])?1:0)+ ((a[1]<b[1])?1:0)+ ((a[2]<b[2])?1:0) ;

    cout<<pointsAlice<<" "<<pointsBob<<"\n";
    return 0;
}