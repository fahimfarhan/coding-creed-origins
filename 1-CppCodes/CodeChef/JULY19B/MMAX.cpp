#include <bits/stdc++.h>

using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll int64_t
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);

ll T, N, K, a,b, r,d, F, S, ans;


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

    cin>>T;
    while(T--){
        cin>>N;
        cin>>K;

        d = K/N; // d d d d (d+1) (d+1) ... {r sonkhok (d+1) }
        r = K%N;

        F = r;
        S = N - F;

        if(F<S){    swap(F,S);  }

        ans = 0;
        if(F == S){
            ans = N-1;
        }else{
            ans = S<<1;
        }

        cout<<ans<<"\n";
    }

    return 0;
}