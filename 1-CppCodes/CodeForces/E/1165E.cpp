#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

typedef long long int ll;
// #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 998244353;

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

    int n;
    ll coeff,ans, m,temp, *a, *b;

    cin>>n;
    a = new ll[n+1];
    b = new ll[n+1];

    m = (ll)n;
    for(ll i=1; i<=m; i++){
        cin>>a[i];
        coeff = i*(n-i+1);
        // coeff = coeff%MODULO;
        a[i] = (a[i]*coeff);
    }

    for(int i=1; i<=n; i++){    cin>>b[i];      }

    sort(a+1,a+n+1);
    sort(b+1,b+n+1);

    ans = 0;
    for(int i=1; i<=n; i++){
        temp = (a[i]%MODULO)*b[n-i+1];
        temp = temp%MODULO;
        ans+=temp;
        ans=ans%MODULO;
    }

    cout<<ans<<"\n";


    delete[] a; delete[] b;

    return 0;
}
