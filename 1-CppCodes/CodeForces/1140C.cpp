#include <bits/stdc++.h>
using namespace std;

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

    int n,k;
    vector<pair<ll,ll> > v;
    ll t,b;

    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>t>>b;
        v.push_back({b,t});
    }

    sort(v.begin() , v.end());

    ll ans=0;
    ll maximus = 0;
    int stop1=n-k,stop2=0;
    
    for(int j=0; j<n;j++){
        stop2 = min(j+k,n);
        ans = 0;
        for(int i=j; i<stop2; i++)
        { ans+=v[i].second*v[j].first; maximus = max(maximus, ans);   }
        //ans = ans*v[j].first;
        
    }
    cout<<maximus<<"\n";

    return 0;
}
/*
    int     -2147483648 2147483647
    short   -32768      32767
*/