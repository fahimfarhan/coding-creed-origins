/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */
#include <bits/stdc++.h>

using namespace std;

#define PI 2*acos(0)
# define SIZE 10000007
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

ll T, N;

short fib[SIZE];

ll myPow(){
    ll ret = (ll)1;
    while(ret<=N){
        ret=ret<<1;
    }
    ret = ret>>1;
    return ret;
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
    
    // preprocessing
    // we'll use 1 based indexing
    fib[0] = 0;
    fib[1] = 0;
    fib[2] = 1;

    for(ll i=3; i<SIZE; i++){
        fib[i] = (fib[i-1]+fib[i-2])%10;
        //if(fib[i]>=10){ fib[i]-=10; }
        // cout<<fib[i]<<" ";
    }

    for(int i=0; i<100; i++){    cout<<fib[i]<<"\n"; }

    cin>>T;

    ll r=0;
    while(T--){
        cin>>N;
        //r = log2(N);
        //r = 1<<r;
        r = myPow();
        cout<<fib[r]<<"\n";
    }

    return 0;
}