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

    int T;
    cin>>T;

    ll n,m,k,d, maximus;

    while(T--){
        cin>>n>>m>>k;
        ll cf[n+1];
        cf[0] = m;

        maximus = k;
        for(int i=1; i<=n; i++){    cin>>cf[i];  cf[i]+=cf[i-1];     }
        for(int i=1; i<n; i++){
            d = cf[i+1] - (cf[i]<<1);
            maximus = max(maximus, d);
        }

        if(maximus>k){ cout<<"NO\n"; }
        else{   cout<<"YES\n";  }
    }


    return 0;
}