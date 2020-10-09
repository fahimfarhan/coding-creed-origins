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

ll n, *h1, *h2;

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

    cin>>n;
    //h1 = new ll[n+1];
    //h2 = new ll[n+1];
    ll h1[n+1], h2[n+1];

    for(int i=0; i<n; i++){ cin>>h1[i]; }
    for(int i=0; i<n; i++){ cin>>h2[i]; }

    pair<ll,ll> d = {0,0};

    ll u, v;
    for(int i=0; i<n; i++){
        u = max(d.first, d.second + h1[i]);
        v = max(d.first + h2[i], d.second);

        d = {u,v};
    }

    n = max(d.first, d.second);
    cout<<n<<"\n";
    //delete[] h1;
    //delete[] h2;

    return 0;
}