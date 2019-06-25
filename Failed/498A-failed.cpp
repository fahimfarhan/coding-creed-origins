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

    ll x0,y0, x1,y1,  a, b, c;
    ll f,s,ans = 0;
    ll m;
    int n;
    cin>>x0>>y0;
    cin>>x1>>y1;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a>>b>>c;
        f = a*x0+b*y0+c;
        s = a*x1+b*y1+c;
        m = f*s;
        if( ((f<0) && (s>0)) || ((f>0) && (s<0)) ){
            ans++;
        }
    }

    cout<<ans<<"\n";


    return 0;
}
