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
vector<ll> v;

ll *dp;

ll mydp(ll n){
    if(n<v[0]){ return dp[n];   }
    
    ll temp=0, ret=0;
    ll minimus = INT_MAX;
    for(int i=0; i<v.size(); i++){
        temp = n-v[i];
        if(temp<0){
            // don't call recursion/dp 
            // just n is the remainder
            minimus = min(n, minimus);
        }else{
            temp = mydp(temp);
            minimus = min(temp, minimus);
        }
    }
    dp[n] = minimus;
    return dp[n];
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
    dp = new ll[n+1];
    dp[0] = 0;
    for(int i=0; i<=n; i++){    dp[i] = INT_MAX; }

    ll dollar[] = {1,2,5,10,20,50,100};
    ll euro[] = {5,10,20,50,100, 200};

    for(int i=0; i<7; i++){ v.push_back( (d*dollar[i]) );}
    for(int i=0; i<6; i++){ v.push_back( (e*euro[i]) );}

    sort(v.begin(), v.end());

    for(int i=0; i<v[0]; i++){  dp[i] = i; }

    ll result = mydp(n);

    cout<<result<<"\n";

    return 0;
}