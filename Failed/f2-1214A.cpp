/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */
#include <bits/stdc++.h>

using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;s
vector<int> *g;
bool *isvisited;

ll *dp;
vector<ll> v;

ll rec(ll N){
    
    if(N<0){    return INT_MAX; }
    if(N==0){   dp[N] = 0; return 0;  }
    if(N<v[0]){ dp[N] = N; return dp[N];     }
    if(dp[N]!=INT_MAX){ return dp[N];   }
    else{
        ll minimus = INT_MAX, temp = 0;
        for(int i=0; i<v.size(); i++){
            temp = N-v[i];
            if(temp>=0){ minimus = min(minimus, rec(temp));   }
            
        }
        dp[N] = min(minimus, dp[N]);
    }
    return 0;
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

    ll n, d, e;

    cin>>n;
    cin>>d;
    cin>>e;

    dp = new ll[n+10];

    for(int i=0; i<=n; i++){ dp[i] = INT_MAX;    }
    
    ll dollar[] = {1,2,5,10,20,50,100};
    ll euro[] = {5,10,20,50,100, 200};

    for(int i=0; i<7; i++){ v.push_back( (d*dollar[i]) );}
    for(int i=0; i<6; i++){ v.push_back( (e*euro[i]) );}

    sort(v.begin(), v.end());

    ll ans = rec(n);
    cout<<ans<<"\n";
    return 0;
}