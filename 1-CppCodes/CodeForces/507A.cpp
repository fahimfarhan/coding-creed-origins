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

    int n,k, x;

    vector<pair<int,int> > v;

    cin>>n>>k;
    for(int i=01; i<=n; i++){
        cin>>x;
        v.push_back({x,i});
    }

    sort(v.begin(), v.end());

    // for(int i=0; i<n; i++){ cout<<v[i].first<<" "; }cout<<"\n";
    for(int i=1; i<n; i++){
        v[i].first += v[i-1].first;
    }

    int j=0;
    for(int i=0; i<n; i++){
        if(v[i].first>k){   break; }
        j++;  
    }

    cout<<j<<"\n";
    for(int i=0; i<j; i++){
        cout<<v[i].second<<" ";
    }cout<<"\n";

    return 0;
}
