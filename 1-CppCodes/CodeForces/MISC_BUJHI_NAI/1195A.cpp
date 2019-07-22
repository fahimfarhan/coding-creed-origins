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

    ll n,m,k, d;
    cin>>n>>k;

    ll a[k+1]={0};
    for(int i=0; i<n; i++){
        cin>>m;
        a[m]++;
    }

    d = 0;
    for(int i=0; i<=k; i++){
        if( (a[i]&1) == 1){    d++;    }
    }
    d = d>>1;
    m = n-d;
    cout<<m<<"\n";
    return 0;
}