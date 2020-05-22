#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)
#define N ((1<<18)+1)

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

int64_t dp[N];

int64_t f(int64_t in){
    int64_t in1;
    if(dp[in]!=-2){ return dp[in]; }
    if( (in%5)==0 ){ 
        in1 = in/5; 
        dp[in] = f(in1);
    }else if((in%3)==0){
        in1 = in/3; 
        dp[in] = f(in1);
    }else if((in%2)==0){
        in1 = in/2; 
        dp[in] = f(in1);
    }else{
        dp[in] = -1; 
    }

    return dp[in];
}

void preprocess(){
    for(int i=0; i<N; i++){ dp[i] = -2; }
    dp[0] = -1; dp[1] = 0;  dp[2] = 1; dp[3] = 2; dp[5] = 3;

    for(int i=1; i<N; i++){ f(i);   }
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

//    a[0] = 01;
//    cout<<a[0]<<"\n";

    int q;
    int64_t x;

    cin>>q;
    
    while(q--){
        cin>>x;
        cout<<dp[x]<<"\n";
    }

    return 0;
}
