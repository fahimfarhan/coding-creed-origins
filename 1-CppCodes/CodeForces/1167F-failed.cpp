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

int n;
ll *a, *b;

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
    a = new ll[n+1];
    // b = new ll[n+1];

    for(int i=1; i<=n; i++){    cin>>a[i];  }

    sort(a+1, a+n+1);

    ll ans = 0, temp=0;
    for(int i=1; i<=n; i++){
        temp = i*(n-i+1);
        temp = temp%MODULO;
        temp = temp*a[i]*i;
        temp = temp%MODULO;
        ans+=temp;
        ans = ans%MODULO; 
    }

    cout<<ans<<"\n";


    // delete[] b;
    delete[] a;
    return 0;
}
