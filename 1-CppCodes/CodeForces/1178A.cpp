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

ll n, total;
vector<ll> v, a;

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
    ll c=0;

    total = 0;
    for(int i=0; i<n; i++){
        cin>>c; a.push_back(c); total+=c;
    }

    ll alice_has = a[0];
    ll coalition= alice_has;
    v.push_back(1);

    
    for(int i=1; i<n; i++){
        if(coalition > (total/2) ){    break; }
        c = a[i];
        if( alice_has>=(2*c) ){
            coalition+=c;
            v.push_back( (i+1) );
        }
    }

    if(coalition<=(total/2)){    cout<<0<<"\n";  }
    else{
        cout<<v.size()<<"\n";
        for(int i=0; i<v.size();i++ ){
            cout<<v[i]<<" ";
        }cout<<"\n";
    }

    return 0;
}