#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);
bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;
vector<int> *g;
bool *isvisited;

int main(int argc, char const *argv[])
{
    /* code */
  /* Soln soln */
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

    double n,r,R, theta, secA;
    
    cin>>n>>r;
    theta = 1.0*PI/n;
    //secA = 1.0/sin(theta);
    

    R = ( r*sin(theta) )/( 1 - sin(theta) );
    
    cout << setprecision(8);
    cout << R << endl;
    return 0;
}
