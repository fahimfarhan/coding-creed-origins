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

#define N 93
ll fib[N]={0};

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
    fib[0] = 0; 
    fib[1] = 1;
    for(int i=2; i<N; i++){ fib[i] = fib[i-1]+fib[i-2]; }
    // for(int i=0; i<N; i++){ cerr<<fib[i]<<" "; }cerr<<"\n";
    ll T=0, n=0, even=0, odd=0;
    int i=0;

    cin>>T;
    while(T--){
        cin>>n;
        i = lower_bound(fib, fib+N, n)-fib;
        even = (int)(i/3);
        even = even+1;

        odd = i+1-even;

        cout<<even<<" "<<odd<<"\n";
    }


    return 0;
}