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

ll *dp;

int coin[5] = {1,5,10,20,100};

int r(int m){
    if(m<0){return -1; }
    if( (m==0)  ){ return 0;   }
    if(m==1){   return 1; }
    int ret=INT_MAX;
    int temp;
    for(int i=4; i>=0; i--){
        temp = m-coin[i];
        temp = r(temp);
        if(temp!=-1){  ret = min(ret, temp);  }
        
    }
    //if(ret==0){ return 0; }
    return (ret+1);
}

ll dpr(ll m){
    if(dp[m]!=INT_MAX){ return dp[m];   }
    if( m<0 ){return -1; }
    if( (m==0) ){ return 0;   }
    if(m==1){   return 1; }
    ll x=INT_MAX;
    ll index;
    for(int i=4; i>=0; i--){
        index = m-coin[i];
        if(index>=0){
            if(dp[index]==INT_MAX){ dp[index]=dpr(index); }
            x = min(x, dp[index]);  
        }
    }
    //if(ret==0){ return 0; }
    x = x+1;
    dp[m] = x;
    return dp[m];
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

    int N;
    cin>>N;
    dp = new ll[N+1];
    for(int i=0; i<=N; i++){    dp[i]=INT_MAX; }
    dp[0]=0; dp[1]=1;

    cout<<dpr(N)<<"\n";

    // for(int i=0; i<=N; i++){   cout<<i<<" "<<dp[i]<<"\n";  }
    delete[] dp;
    return 0;
}
