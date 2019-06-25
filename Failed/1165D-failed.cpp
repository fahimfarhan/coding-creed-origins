#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;
vector<int> *g;
bool *isvisited;

ll N = 1000005;
vector<ll> v[1000005];
map< vector<ll>, int> mp;

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

    // preprocess
    for(int i=2; i*i<=N; i++){
        for(int j=i; j<=N; j+=i){
            v[j].push_back(i);
        }
    }

    for(int i=0; i<N; i++){
        mp[v[i]] = i;
    }

    int t,m; ll x;
    
    cin>>t;
    while(t--){
        vector<ll> a;
        ll maximus = 0;
        cin>>m;
        for(int i=0; i<m; i++){
            cin>>x;
            a.push_back(x);
            maximus = max(x, maximus);
        }
        sort(a.begin(), a.end());
        if(mp[a] == 0){
            cout<<"-1\n";
        }else{
            cout<<mp[a]<<"\n";
        }

    }
    return 0;
}
