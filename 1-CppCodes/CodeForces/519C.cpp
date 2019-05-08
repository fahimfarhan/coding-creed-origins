#include <bits/stdc++.h>
using namespace std;
#define MODULO 1e9+7
#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;
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

    int ans,x,y,n,m;
    cin>>n>>m;
    if(n>m){    n=n^m; m=n^m; n=n^m;    }

    x = min(n,(m>>1) );

    n=n-x; m-m-(x<<1);

    y = min((n>>1), m);

    ans = x+y;
    cout<<ans<<"\n";

    
    return 0;
}
