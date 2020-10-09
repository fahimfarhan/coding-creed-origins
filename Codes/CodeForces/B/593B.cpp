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

bool comparator(pair<ll,ll> f, pair<ll,ll> s){
    return (f.first<s.first);
}

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

    int n; ll x1,x2;
    pair<ll,ll> *a;
    cin>>n;
    cin>>x1>>x2;
    a = new pair<ll,ll>[n+1];

    ll f,s;
    for(int i=0; i<n; i++){
        cin>>f>>s;
        a[i].first = f; a[i].second = s;
    }

    
    sort(a,a+n,comparator);
    if(!a)delete[] a;
    return 0;
}
