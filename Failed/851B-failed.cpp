#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

typedef long long int ll;
// #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;s
vector<int> *g;
bool *isvisited;

int main(int argc, char const *argv[])
{
    /* code */
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    cout << setprecision(8);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll x[3], y[3];
    ll ab, bc;
    
    for(int i=0; i<3; i++){
    	cin>>x[i]>>y[i];
    }

    ab = (x[0]-x[1])*(x[0]-x[1]) + (y[0]-y[1])*(y[0]-y[1]);
    bc = (x[02]-x[1])*(x[02]-x[1]) + (y[02]-y[1])*(y[02]-y[1]);

    if(ab == bc ){ cout<<"Yes\n";  }
    else{	   cout<<"No\n";   }

    return 0;
}
