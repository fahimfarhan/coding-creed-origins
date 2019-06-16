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

    ll n,a,b;

    cin>>n;
    cin>>a;
    cin>>b;

    if( (n&1) == 1){
        if( ((a&1) == 0) && ((b&1)==0) ){
            cout<<"NO\n";
            exit(0);
        }
    }

    ll ul_a=1+n/a, ul_b=1+n/b;
    ll x,y;

    for(ll i=0; i<=ul_a; i++){
        for(ll j=0; j<=ul_b; j++){
            if( (a*i + b*j) == n ){
                x = i; y = j;
                cout<<"YES\n";
                cout<<x<<" "<<y<<"\n";
                exit(0);
            }
        }
    }

    cout<<"NO\n";

    return 0;
}
