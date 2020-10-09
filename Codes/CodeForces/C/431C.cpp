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

ll n,k,d;

ll dp[110][2];

ll myAdd(const ll& a, const ll& b){
    ll ret=a+b;
    if(ret>=MODULO){ ret-=MODULO; }
    return ret;
}

ll DP(ll N, int istaken){
    // base case
    if(N<0){    return 0; }
    if(dp[N][istaken]!=-1){ return dp[N][istaken];  }
    if(N==0 && istaken == 0){   dp[N][istaken]=0; return dp[N][istaken];     }
    if(N==0 && istaken==1){     dp[N][istaken]=1; return dp[N][istaken]; }

    ll ret = 0;
    ll temp=0;
    for(int i=1; i<=k; i++){
        temp = N-i;
        if(i>=d){   ret=myAdd(ret,DP(temp,true) );    }
        else{
            ret=myAdd(ret,DP(temp, istaken));
        }
    }
    dp[N][istaken] = ret; 
    ret%MODULO;
    return dp[N][istaken];
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

    // preprocess 
    for(int i=0; i<110; i++){   dp[i][0] = -1; dp[i][1] = -1; }

    cin>>n>>k>>d;
    cout<<DP(n,0)<<"\n";
    return 0;
}